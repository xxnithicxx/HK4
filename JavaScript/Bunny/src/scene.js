import { Carrot, Bullet } from './object.js'

export default class Game extends Phaser.Scene {
    /**@type {Phaser.Physics.Arcade.Sprite} */
    player

    /**@type {Phaser.Physics.Arcade.StaticGroup} */
    platforms

    /**@type {Phaser.Types.Input.Keyboard.CursorKeys} */
    cursors

    /**@type {Phaser.Physics.Arcade.Group} */
    carrots

    /**@type {Phaser.Physics.Arcade.Group} */
    bullet

    /**@type {Phaser.Input.Pointer} */
    mouse

    /**@type {Boolean} */
    isShoot

    constructor() {
        super({ key: 'Game' });
        this.isShoot = false
    }

    preload() {
        this.load.image('background', 'assets/PNG/Background/bg_layer1.png');
        this.load.image('platform', 'assets/PNG/Environment/ground_grass.png');
        this.load.image('bunny-stand', 'assets/PNG/Players/bunny1_stand.png');
        this.load.image('carot', 'assets/PNG/Items/carrot.png');
        this.load.image('bullet', 'assets/PNG/Items/bubble.png');
    }

    create() {
        this.add.image(240, 320, 'background').setScrollFactor(1, 0)

        this.platforms = this.physics.add.staticGroup()
        // then create 5 platforms from the group
        for (let i = 0; i < 5; ++i) {
            const x = Phaser.Math.Between(80, 400)
            const y = 150 * i

            /** @type {Phaser.Physics.Arcade.Sprite} */
            const platform = this.platforms.create(x, y, 'platform')
            platform.scale = 0.5

            /** @type {Phaser.Physics.Arcade.StaticBody} */
            const body = platform.body
            body.updateFromGameObject()
        }

        this.player = this.physics.add.sprite(240, 320, 'bunny-stand').setScale(0.5)

        this.physics.add.collider(this.platforms, this.player)

        this.player.body.checkCollision.up = false
        this.player.body.checkCollision.right = false
        this.player.body.checkCollision.left = false

        this.cameras.main.startFollow(this.player)
        this.cameras.main.setDeadzone(this.scale.width * 1.5)
        this.cameras.main.setZoom(2)

        this.cursors = this.input.keyboard.createCursorKeys()
        this.mouse = this.input.activePointer

        this.carrots = this.physics.add.group({
            classType: Carrot
        })

        this.platforms.children.iterate(child => {
            /** @type {Phaser.Physics.Arcade.Sprite} */
            const platform = child
            // platform.body.updateFromGameObject()

            this.addCarotAbove(platform)
        })

        this.physics.add.collider(this.platforms, this.carrots)
        this.physics.add.overlap(this.player, this.carrots, this.handleCollectCarrot, undefined, this)
        this.player.setCollideWorldBounds(true)

        let x = this.player.x + 35
        let y = this.player.y - 25

        this.bullet = this.physics.add.image(x, y, 'bullet').setScale(0.1)
    }

    update() {
        const touchingDown = this.player.body.touching.down

        if (touchingDown) {
            this.player.setVelocityY(-300)
            if (!this.isShoot)
                this.bullet.setVelocityY(-300)
        }

        this.platforms.children.iterate(child => {
            /** @type {Phaser.Physics.Arcade.Sprite} */
            const platform = child
            const scrollY = this.cameras.main.scrollY
            if (platform.y >= scrollY + 700) {
                platform.y = scrollY - 30
                platform.x = Phaser.Math.Between(80, 400)
                platform.body.updateFromGameObject()

                this.addCarotAbove(platform)
            }
        })

        this.carrots.children.iterate(child => {
            /** @type {Carrot} */
            const carrot = child
            const scrollY = this.cameras.main.scrollY
            if (carrot.y >= scrollY + 700) {
                this.carrots.killAndHide(carrot)
                this.physics.world.disableBody(carrot.body)
            }
        })

        // left and right input logic
        if (this.cursors.left.isDown && !touchingDown) {
            this.player.setVelocityX(-200)
            if (!this.isShoot)
                this.bullet.setVelocityX(-200)
        }
        else if (this.cursors.right.isDown && !touchingDown) {
            this.player.setVelocityX(200)
            if (!this.isShoot)
                this.bullet.setVelocityX(200)
        }
        else {
            // stop movement if not left or right
            this.player.setVelocityX(0)
            if (!this.isShoot)
                this.bullet.setVelocityX(0)
        }

        // if left mouse is clicked, shoot bullet
        if (this.mouse.leftButtonDown() && !this.isShoot) {
            let angle = Phaser.Math.Angle.Between(this.player.x, this.player.y, this.mouse.x, this.mouse.y)
            this.bullet.setVelocity(Math.cos(angle) * 300, Math.sin(angle) * 300)
            this.bullet.body.allowGravity = false
            this.isShoot = true
        }
        else if (this.cursors.space.isDown && this.isShoot) {
            this.bullet.setVelocity(0, 0)
            this.bullet.body.allowGravity = true
            this.isShoot = false
            this.teleport()
            this.resetBullet()
        }

        this.horizontalWrap(this.player)
    }

    /**
    * @param {Phaser.GameObjects.Sprite} sprite
    */
    horizontalWrap(sprite) {
        const halfWidth = sprite.displayWidth * 0.5
        const gameWidth = this.scale.width
        if (sprite.x < -halfWidth) {
            sprite.x = gameWidth + halfWidth
        }
        else if (sprite.x > gameWidth + halfWidth) {
            sprite.x = -halfWidth
        }
    }

    /**
     * 
     * @param {Phaser.Physics.Arcade.Sprite} sprite 
     */
    addCarotAbove(sprite) {
        const y = sprite.y - sprite.displayHeight
        /** @type {Phaser.Physics.Arcade.Sprite} */
        const carrot = this.carrots.get(sprite.x, y, 'carot')

        carrot.setActive(true)
        carrot.setVisible(true)

        this.add.existing(carrot)
        carrot.body.setSize(carrot.width, carrot.height)

        this.physics.world.enable(carrot)

        return carrot
    }

    /**
     * 
     * @param {Phaser.Physics.Arcade.Sprite} player 
     * @param {Carrot} carrot 
     */
    handleCollectCarrot(player, carrot) {
        this.carrots.killAndHide(carrot)
        this.physics.world.disableBody(carrot.body)
    }

    resetBullet() {
        this.bullet.setVelocity(0, 0)

        let x = this.player.x + 35
        let y = this.player.y - 25

        this.bullet.setPosition(x, y)
    }

    teleport() {
        let x = this.bullet.x
        let y = this.bullet.y

        this.player.setPosition(x, y)
    }
}