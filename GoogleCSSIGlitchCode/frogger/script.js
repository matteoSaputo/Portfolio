// Since this example code uses the p5 collide2d library, be sure to remind
// students to load it in. Model how to do this by either connecting a local
// copy (included in the templates), connecting a hosted copy through a CDN, or
// (as a last resort) by pasting it in its entirety in this script as the first
// line.

let backgroundColor,
  frogX,
  frogY,
  score,
  highScore,
  lives,
  gameIsOver,
  car1X,
  car1Y,
  car1V,
  car2X,
  car2Y,
  car2V,
  car3X,
  car3Y,
  car3V,
  car4X,
  car4Y,
  car4V,
  jump;

function setup() {
  // Canvas & color settings
  createCanvas(500, 500);
  colorMode(HSB, 360, 100, 100);
  backgroundColor = 0;
  frogX = random(width);
  frogY = 450;
  score = 0;
  highScore = 0;
  lives = 3;
  gameIsOver = false;
  car1X = 0;
  car1Y = 380;
  car1V = 3;
  car2X = width;
  car2Y = 280;
  car2V = -6;
  car3X = 0;
  car3Y = 180;
  car3V = 9;
  car4X = frogX;
  car4Y = 80;
  car4V = .95;
  jump = 20;
}

function draw() {
  background(backgroundColor);
  // Code for gold goal line
  fill(60, 80, 80);
  rect(0, 0, width, 50);
  // Code to display Frog
  fill(120, 80, 80);
  ellipse(frogX, frogY, 20);
  moveCars();
  drawCars();
  checkCollisions();
  checkWin();
  displayScores();
  if(gameIsOver){
    gameOver();
  }
}

function keyPressed() {
  if (keyCode === UP_ARROW) {
    frogY -= jump;
  }
  if (keyCode === DOWN_ARROW) {
    frogY += jump;
  }
  if (keyCode === LEFT_ARROW) {
    frogX -= jump;
  }
  if (keyCode === RIGHT_ARROW) {
    frogX += jump;
  }
  if(gameIsOver){
    if(keyCode === 32){
      lives = 3;
      score = 0;
      gameIsOver = false;
    }
  }
}

function moveCars() {
  // Move the car
  // Reset if it moves off screen
  car1X += car1V;
  car2X += car2V;
  car3X += car3V;
  if(car4X + 20 < frogX){
    car4X += car4V;
  }else{
    car4X -= car4V;
  }
  if(car1X >= 500){
    car1X = 0;
  }
  if(car2X+40 <= 0){
    car2X = width;
  }
  if(car3X >= 500){
    car3X = 0;
  }
}

function drawCars() {
  // Code for car 1
  fill(0, 80, 80);
  rect(car1X, car1Y, 40, 30);
  rect(car2X, car2Y, 40, 30);
  rect(car3X, car3Y, 40, 30);
  rect(car4X, car4Y, 40, 30);
  // Code for additional cars
}

function checkCollisions() {
  // If the frog collides with the car, reset the frog and subtract a life.
  hit = collideRectCircle(car1X, car1Y, 40, 30, frogX, frogY, 20);
  hit2 = collideRectCircle(car2X, car2Y, 40, 30, frogX, frogY, 20);
  hit3 = collideRectCircle(car3X, car3Y, 40, 30, frogX, frogY, 20);
  hit4 = collideRectCircle(car4X, car4Y, 40, 30, frogX, frogY, 20);
  
  if(hit || hit2 || hit3 || hit4){
    frogY = 450;
    frogX = 250;
    lives--;
  }
}

function checkWin() {
  // If the frog makes it into the yellow gold zone, increment the score
  fin = collideRectCircle(0, 0, width, 50, frogX, frogY, 20);
  // and move the frog back down to the bottom.
  if(fin){
    score++;
    frogY = 450;
    frogX = 250;
  }
  if(lives < 0){
    lives = 0;
    gameIsOver = true;
  }
}

function displayScores() {
  textSize(12);
  fill(0);
  // Display Lives
  text(`Lives: ${lives}`, 10, 20);
  // Display Score
  text(`Score: ${score}`, 10, 40);
  // Display High Score
  text(`High Score: ${highScore}`, 70, 20);
  if(score > highScore){
    highScore = score;
  }
}

function gameOver(){
  background(backgroundColor);
  textSize(32);
  fill("green");
  text(`GAME OVER`, 0, 32);
  fill("red");
  text(`Score: ${score}`, 0, 100);
  text(`High Score: ${highScore}`, 0, 150);
  fill(255);
  text(`PRESS SPACE TO PLAY AGAIN`, 0, 200);
}
