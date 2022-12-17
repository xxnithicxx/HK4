export class Carrot extends Phaser.Physics.Arcade.Sprite {
    /**
     * 
     * @param {Phaser.Scenes} scene 
     * @param {integer} x 
     * @param {integer} y 
     * @param {Phaser.Loader.LoaderPlugin} texture 
     */
    constructor(scene, x, y, texture) {
        super(scene, x, y, texture)
        this.setScale(0.5)
    }
}

export class Bullet extends Phaser.Physics.Arcade.Sprite {
    /**
     * 
     * @param {Phaser.Scenes} scene 
     * @param {integer} x 
     * @param {integer} y 
     * @param {Phaser.Loader.LoaderPlugin} texture 
     */
    constructor(scene, x, y, texture) {
        super(scene, x, y, texture)
        this.setScale(0.5)
    }
}