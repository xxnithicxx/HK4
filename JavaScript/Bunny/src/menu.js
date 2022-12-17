var textConfig = {
    fontFamily: 'SVN-Beast',
    fontSize: '28px',
    fill: '#000000',
    align: 'justify',
    wordWrap: {
        width: 500
    },
    resolution: 2
}

class Game extends Phaser.Scene {
    cursors

    constructor() {
        super("Game");
    }

    preload() {
        this.load.image('background', 'assets/PNG/Background/bg_layer1.png');
        this.load.image('platform', 'assets/PNG/Environment/ground_grass.png');
        this.cursors = this.input.keyboard.createCursorKeys();
    }

    create() {
        this.add.image(0, 0, 'background').setOrigin(0, 0);
        this.add.text(20, 20, "Playing game", textConfig);
        this.add.image(400, 400, 'platform');
        this.add.image(200, 200, 'platform');
    }

    update() {
        if (this.cursors.space.isDown) {
            this.scene.start("Menu");
        }

        if (this.cursors.shift.isDown) {
            this.scene.launch("popUp", {
                message: "Hello from Game scene to PopUp scene, how are you?",
                scene: "Game"
            });
            this.scene.pause()
        }
    }
}

class Menu extends Phaser.Scene {

    constructor() {
        super({ key: 'Menu' });
    }

    preload() {
        this.load.image('frameChoice', 'assets/PNG/HUD/Btn_V15.png')
    }
    create() {
        const containerMain = this.add.container(400, 300);

        const containerChoice1 = this.add.container(0, 0);
        containerChoice1.add(this.add.image(0, 0, 'frameChoice'));
        containerChoice1.add(this.add.text(0, 0, 'Resume', textConfig))
        Phaser.Display.Align.In.Center(containerChoice1.getAt(1), containerChoice1.getAt(0));
        containerChoice1.setInteractive(new Phaser.Geom.Rectangle(-50, -50, 100, 100), Phaser.Geom.Rectangle.Contains);

        containerChoice1.addListener('pointerdown', () => {
            this.scene.start('Game');
        });

        containerMain.add(containerChoice1);

        Phaser.Display.Align.In.Center(containerMain, this.add.zone(400, 300, 800, 600));
    }
    update() { };

};

class PopUp extends Phaser.Scene {
    message
    preScene

    constructor() {
        super({ key: 'popUp' });
    }

    init(data) {
        this.message = data.message;
        this.preScene = data.scene;
    }

    preload() {
        // this.load.image('x', 'images/grey_boxCross.png')
        // this.load.image('box', 'image/grey_panel.png')
        this.load.image('box', '../Bunny/assets/PNG/images/grey_panel.png')
        this.load.image('x', '../Bunny/assets/PNG/images/grey_boxCross.png')
    }

    create() {
        let screenW = this.sys.game.config.width;
        let screenH = this.sys.game.config.height;

        var container = this.add.container(screenW / 2, screenH / 2);

        container.add(this.add.image(0, 0, 'box'). setScale(5, 5));
        container.add(this.add.image(0, 0, 'x'));
        container.add(this.add.text(0, 0, this.message, textConfig));
        Phaser.Display.Align.In.Center(container.getAt(2), container.getAt(0));
        Phaser.Display.Align.In.TopRight(container.getAt(1), container.getAt(0), 200, 200);
        container.setInteractive(
            new Phaser.Geom.Rectangle(-screenW / 2, -screenH / 2, screenW, screenH),
            Phaser.Geom.Rectangle.Contains
        )

        container.addListener('pointerdown', () => {
            this.scene.resume(this.preScene);
            this.scene.stop();
        });

    }
    update() { };
}

var config = {
    type: Phaser.AUTO,
    width: 800,
    height: 600,
    scene: [Game, Menu, PopUp],
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
