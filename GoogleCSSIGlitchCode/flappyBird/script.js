// Be sure to name any p5.js functions we use in the global so Glitch can recognize them.
// Add to this list as you consult the p5.js documentation for other functions. 
/* global createCanvas, colorMode, HSB, width, height, random, background, fill, color, random,
          rect, ellipse, stroke, image, loadImage, collideCircleCircle, collideRectCircle, text, 
          mouseX, mouseY, strokeWeight, line, mouseIsPressed, windowWidth, windowHeight, noStroke, 
          keyCode, UP_ARROW, LEFT_ARROW, RIGHT_ARROW, DOWN_ARROW, textSize, framecount */

let backgroundColor;


var pipes = [];
var bird;

// #1 First Finish the Pipe Class
// #2 Initialize the Pipe, Bird
// #3 Complete the Code in draw()

function setup() {
  // Canvas & color settings
  //let img = loadImage("https://toppng.com/uploads/preview/flappy-bird-no-background-11549936960agq8fxhfbr.png")
  createCanvas(640, 480);
  colorMode(HSB, 360, 100, 100);
  backgroundColor = 0  ;
  
  //TODO Initialize pipes and bird
  pipes.push(new Pipe());
  bird = new Bird();
}

function draw() {
  background(backgroundColor);
  
  bird.show();
  bird.update();  
  for(let i = pipes.length-1; i >= 0; i--){
    pipes[i].show();
    pipes[i].update();
    if(pipes[i].offscreen()){
      pipes.splice(i, 1)
    }
  }
  
  
  //TODO - Loop through Pipe Array Showing/Updating each one
  // Splice Pipe after it goes offscreen
  // within the loop, you'll check for a bird hit
  //TODO: Add Code for Bird HiT within the loop, but also code the method in BirdClass

  //TODO - If Current Pipe scrolled 75% of Canvas, the add a new pipe
  if(frameCount % 75 == 0){
    pipes.push(new Pipe());
  }
 
}
function keyPressed() {
  if (keyCode === 32) {
    bird.up();
    //console.log("SPACE");
  }
}


// Let's Define the Pipe Class!

class Pipe {
  
  constructor(){
  
    //TODO - Code the attributes, 7 in total - spacing,top,bottom,x,w,speed,highlight
    this.spacing = 175;
    this.top = random(height/6, (3/4)*height);
    this.bottom = height - (this.top + this.spacing);
    this.x = width;
    this.w = 80;
    this.speed = 6;
    this.highlight = false;
    
  }
  
  //TODO: Code Method for Bird Hit

  show () {
   //TODO: Draw the Pipe
    fill(255);
    rect(this.x, 0, this.w, this.top);
    rect(this.x, height - this.bottom, this.w, this.bottom);
  }

  update() {
    //TODO: Speed of Scrolling Pipe
    this.x -= this.speed;
  }

  offscreen() {
    //TODO: Code the offscreen
    if(this.x < -this.w){
      return true;
    }else{
      return false;
    }
  }
}

class Bird {
  
  constructor(){
    this.y = height / 2;
    this.x = 64;
    this.gravity = 0.7;
    this.lift = -20;
    this.velocity = 0;
  }

  show() {
    fill(255);
    ellipse(this.x, this.y, 32, 32);
  }

  up () {
    this.velocity += this.lift;
  }

  update() {
    //TODO
    this.velocity += this.gravity;
    this.velocity *= 0.9;
    this.y += this.velocity;

    if (this.y > height) {
      this.y = height;
      this.velocity = 0;
    }

    if (this.y < 0) {
      this.y = 0;
      this.velocity = 0;
    }
  }
}