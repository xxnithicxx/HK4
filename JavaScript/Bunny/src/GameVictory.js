class GameVictory extends Phaser.Scene {
    constructor() {
        super('game-over')
    }

    create() {
        const { width, height } = this.scale

        this.add.text(width * 0.5, height * 0.3, 'Game Victory', {
            fontFamily: 'Arial',
            fontSize: '15px',
            color: '#ffffff'
        }).setOrigin(0.5)

        const button = this.add.rectangle(width * 0.5, height * 0.55, 150, 75, 0xffffff)
            .setInteractive()
            .on(Phaser.Input.Events.GAMEOBJECT_POINTER_UP, () => {
                this.scene.start('game')
            })

        this.add.text(button.x, button.y, 'Play Again', {
            color: '#000000'
        }).setOrigin(0.5)

        this.cameras.main.setRoundPixels(true);
    }
}

var config = {
    type: Phaser.AUTO,
    width: 800,
    height: 600,
    scene: [GameVictory],
    physics: {
        default: 'arcade',
        arcade: {
            gravity: { y: 200 },
            debug: true
        }
    }
}

class Main extends Phaser.Game {
    constructor() {
        super(config);
    }

    create() {
    }
}

export default new Main();