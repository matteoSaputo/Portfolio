// Name any p5.js functions we use in the global so Glitch can recognize them.
/* global createCanvas text textSize sphere millis WEBGL rotateX rotateY rotateZ frameCount rotate PI arc line mouseIsPressed colorMode HSB random strokeWeight background rect mouseX mouseY stroke fill ellipse */

let x, y;

function setup() {
  createCanvas(400, 400, WEBGL);
  strokeWeight(3);
  x = 20;
  y = 20;
}

/*function draw() {
  
  background(240);
  //rotateX(frameCount/100);
  rotateY(frameCount/100);
  rotateZ(frameCount/100);
  shininess(20);
  ambientLight(50);
  specularColor(255, 0, 0);
  pointLight(255, 0, 0, 0, -250, 250);
  specularColor(255, 255, 255);
  pointLight(255, 255, 255, 0, 200, 200);
  specularMaterial(255);
  sphere(40);
}*/

function draw() {
  background(240);
  // textSize(15);
  // fill(0, 102, 153);
  // text('Click the Screen', 50, 50);
  
  if(mouseIsPressed){
    rotateZ(millis() / 200);
  }else{
    rotateZ(millis() / 500);
  }
  
  //top half of pokeball
  fill("red")
  arc(x, y, 200, 200, PI, 0);
  
  //bottom half of pokeball
  fill("white");
  arc(x, y, 200, 200, 0, PI);
  
  //line separating top and bottom halves of pokeball
  strokeWeight(4);
  line (x-100, y, x+100, y);
  fill("black");
  ellipse(x, y, 50);
  fill("white")
  ellipse(x, y, 25);
  strokeWeight(3);
}

