// Name any p5.js functions we use in the global so Glitch can recognize them.
/* global createCanvas, colorMode, HSB, width, height, random, background, fill, color, random,
          rect, ellipse, stroke, image, loadImage, collideCircleCircle, collideRectCircle, text, 
          mouseX, mouseY, strokeWeight, line, mouseIsPressed, windowWidth, windowHeight, noStroke, 
          keyCode, UP_ARROW, LEFT_ARROW, RIGHT_ARROW, DOWN_ARROW, textSize, framecount, collideRectRect, 
          keyIsPressed, round, collideLineLine, collideLineRect, lives, hit, noFill*/

let backgroundColor,
  playerCharacter,
  ground1,
  ground2,
  moving,
  spacing,
  groundSpeed,
  hit1,
  hit2,
  hit3,
  playerSpeed,
  obstacle,
  topHit,
  bottomHit,
  sideHit,
  started,
  score,
  showPitPoints,
  n,
  lives,
  restartGame;

let q, questioning, timer, gameIsOver, scoreColor;

function setup() {
  createCanvas(500, 500);
  colorMode(HSB, 360, 100, 100);
  backgroundColor = "skyBlue";
  n = 0;
  scoreColor = "green";
  moving = false;
  started = false;
  showPitPoints = false;
  gameIsOver = false;
  //gameIsOver = true;
  spacing = 150;
  groundSpeed = 4;
  playerSpeed = 3;
  score = 0;
  lives = 3;

  questioning = false;
  timer = 0;

  ground1 = {
    x: 0,
    y: 250,
    l: 499,
    w: 249
  };
  ground2 = {
    x: 500 + spacing,
    y: 250,
    l: 0,
    w: 249
  };
  playerCharacter = new Player();
  obstacle = new Obstacle();
  q = new Question();
}

function draw() {
  background(backgroundColor);
  displayScores();
  playerCharacter.show();
  obstacle.show();
  if (moving) obstacle.move();
  ground();
  info();
  if (score >= 0) scoreColor = "green";
  else scoreColor = "red";
  // if(timer % 100 == 0)
  //   groundSpeed += 2;
  if (!questioning && started && moving) timer++;
  if (questioning) {
    q.show();
    moving = false;
  }

  if (playerCharacter.jumping && moving) {
    playerCharacter.jump();
  }
  if (
    playerCharacter.y + playerCharacter.size / 2 > ground1.y &&
    playerCharacter.x <= ground2.x
  ) {
    playerCharacter.fall();
  }
  //console.log(playerCharacter.y);
  if (playerCharacter.left && keyIsPressed && playerCharacter.x >= 0) {
    playerCharacter.x -= playerSpeed;
  } else playerCharacter.left = false;
  if (
    playerCharacter.right &&
    keyIsPressed &&
    playerCharacter.x + playerCharacter.size <= width
  ) {
    playerCharacter.x += playerSpeed;
  } else playerCharacter.right = false;
  if (gameIsOver) {
    gameOver();
  }
}

function gameOver() {
  background(20);
  textSize(40);
  fill("red");
  text(`GAME OVER! ಥ_ಥ`, 80, 180);
  if ((score = 0)) scoreColor = 255;
  fill(scoreColor);
  if (scoreColor == "green") text(`Score: ${score} ^_^`, 80, 280);
  else if ((scoreColor = "red")) text(`Score: ${score} ╰（‵□′）╯`, 80, 280);
  else text(`Score: ${score} X_X`, 80, 280);
  fill(255);
  textSize(20);
  text(`(To Many Incorrect Answers)`, 90, 210);
  textSize(30);
  text(`Press Enter to Play Again!`, 80, 320);
}

function keyPressed() {
  if (keyCode == 32 && playerCharacter.y <= 250 - playerCharacter.size) {
    playerCharacter.jumping = true;
  }
  // if(keyCode == 13 && moving){
  //   playerCharacter.resetPosition();
  // }
  if (keyCode == 13 && !started) {
    moving = true;
    started = true;
  }
  if (keyCode == 27 && started && !questioning && !gameIsOver) {
    moving = !moving;
  }
  if (keyCode == LEFT_ARROW && moving) {
    playerCharacter.left = true;
    playerCharacter.right = false;
  }
  if (keyCode == RIGHT_ARROW && moving) {
    playerCharacter.left = false;
    playerCharacter.right = true;
  }
  if (keyIsPressed == false) {
    playerCharacter.left = false;
    playerCharacter.right = false;
  }

  if (questioning) {
    var correctChoice = 49 + q.correctChoice;
    if (keyCode == correctChoice) {
      q = new Question();
      questioning = false;
      moving = true;
      playerCharacter.y = 150;
      playerCharacter.gravityRule = true;
      playerCharacter.gravityIndex = 2;
      playerCharacter.correct = true;
    } else {
      playerCharacter.correct = false;
      lives -= 1;
      score -= 5;
      if (lives < 0) {
        lives = 0;
        gameIsOver = true;
      }
    }
  }

  if (gameIsOver) {
    if (keyCode == 13) {
      resetGame();
    }
  }
}

function resetGame() {
  gameIsOver = false;
  playerCharacter.x = 75;
  playerCharacter.y = 150;
  score = 0;
  lives = 3;
  timer = 0;
  groundSpeed = 4;
  ground1 = {
    x: 0,
    y: 250,
    l: 499,
    w: 249
  };
  ground2 = {
    x: 500 + spacing,
    y: 250,
    l: 0,
    w: 249
  };
  obstacle = new Obstacle();
  started = false;
  questioning = false;
  playerCharacter.correct = null;
  playerCharacter.gravityRule = true;
  playerCharacter.gravityIndex = 2;
  // playerCharacter.jumping = false;
}

function ground() {
  fill("brown");
  //noFill();
  rect(ground1.x, ground1.y, ground1.l, ground1.w);
  rect(ground2.x, ground2.y, ground2.l, ground2.w);
  if (moving) {
    moveGround();
    if (playerCharacter.gravityRule) playerCharacter.gravity();
  }
}

function displayScores() {
  textSize(15);
  fill(0);
  // Display Lives
  text(`Lives: ${lives}`, 420, 60);
  // Display Score
}

function moveGround() {
  ground1.l -= groundSpeed;
  ground2.x -= groundSpeed;
  ground2.l += groundSpeed;
  if (ground1.l < -spacing) {
    ground1.l = 500;
    spacing = random(70, 150);
  }
  if (ground2.x < 0) {
    ground2.x = 500 + spacing;
    showPitPoints = false;
    playerCharacter.correct = null;
  }
}

function info() {
  textSize(15);
  fill(0);
  // text(`X: ${round(playerCharacter.x)}`, 450, 20);
  // text(`Y: ${round(playerCharacter.y)}`, 450, 40);
  text(`Timer: ${timer}`, 420, 20);
  text(`Press Space to Jump`, 0, 20);
  text(`Left/Right Arrows to Move`, 0, 40);
  text(`Press ESC to Pause`, 0, 60);
  text(`Watch Out For Pits and `, 0, 80);
  fill(obstacle.color);
  rect(160, 70, 10, 10);
  fill(scoreColor);
  text(`Score: ${score}`, 420, 40);
  if (playerCharacter.y > height) {
    fill("yellow");
    text(
      `You fell into a pit! Answer correctly to get back in the game!`,
      0,
      290
    );
    questioning = true;
  }
  if (!moving && started) {
    fill("red");
    textSize(50);
    if (!questioning) text(`PAUSED`, 150, 200);
  }
  if (!started) {
    fill(0);
    textSize(40);
    text(`Press Enter to Start`, 90, 210);
  }
  if (
    playerCharacter.madeOverPit &&
    playerCharacter.jumping &&
    playerCharacter.correct == null
  ) {
    showPitPoints = true;
    score += 5;
  }

  if (showPitPoints) {
    textSize(20);
    fill("green");
    text(`+5`, ground2.x, 210);
  }
  if (obstacle.color == "red") {
    textSize(20);
    fill("red");
    text(`-5`, obstacle.x, obstacle.y - 20);
  }
  if (playerCharacter.hitObstacle && n < 1) {
    score -= 5;
    n++;
  }
  playerCharacter.hitObstacle = false;
  if (playerCharacter.correct == false) {
    fill("red");
    textSize(30);
    text(`Incorrect!`, 200, 200);
    textSize(20);
    text(`-1 life/-5 pts`, 200, 170);
  }
  if (playerCharacter.correct) {
    fill("green");
    textSize(30);
    text(`Correct!`, ground2.x - spacing, 240);
  }
}

class Player {
  constructor() {
    this.x = 75;
    this.y = 150;
    this.size = 25;
    this.gravityRule = true;
    this.gravityIndex = 2;
    this.jumpStart = -7;
    this.jumpIndex = 0.3;
    this.jumping = false;
    this.falling = false;
    this.left = false;
    this.right = false;
    this.hitSide = false;

    this.madeOverPit = false;
    this.hitObstacle = false;

    this.correct = null;
  }

  show() {
    fill("green");
    rect(this.x, this.y, this.size, this.size);
    if (this.x + this.size > ground2.x && !showPitPoints) {
      this.madeOverPit = true;
    } else this.madeOverPit = false;
  }

  gravity() {
    hit1 = collideRectRect(
      this.x,
      this.y,
      this.size,
      this.size,
      ground1.x,
      ground1.y,
      ground1.l,
      ground1.w
    );
    hit2 = collideRectRect(
      this.x,
      this.y,
      this.size,
      this.size,
      ground2.x,
      ground2.y,
      ground2.l,
      ground2.w
    );
    obstacle.handleCollision();
    if (!hit1 && !hit2) {
      this.y += this.gravityIndex;
      this.gravityIndex += 0.3;
    } else {
      this.y = 250 - this.size;
      this.gravityIndex = 2;
    }
  }

  jump() {
    this.gravityRule = false;
    this.y += this.jumpStart;
    this.jumpStart += this.jumpIndex;
    // if(this.y <= 140)
    //   this.gravityRule = true;
    // console.log(this.y);
    hit1 = collideRectRect(
      this.x,
      this.y,
      this.size,
      this.size,
      ground1.x,
      ground1.y,
      ground1.l,
      ground1.w
    );
    hit2 = collideRectRect(
      this.x,
      this.y,
      this.size,
      this.size,
      ground2.x,
      ground2.y,
      ground2.l,
      ground2.w
    );
    obstacle.handleCollision();
    if (hit1 || hit2) {
      this.gravityRule = true;
      this.jumping = false;
      this.jumpStart = -7;
      this.jumpIndex = 0.3;
    }
  }

  fall() {
    this.gravityRule = false;
    this.jumping = false;
    this.left = false;
    this.right = false;
    this.y += this.gravityIndex;
    this.gravityIndex += 0.3;
    if (this.x > ground2.x - this.size) this.x = ground2.x - this.size;
  }

  resetPosition() {
    this.x = 75;
    this.y = 150;
    this.gravityRule = true;
    this.gravityIndex = 2;
  }
}

class Obstacle {
  constructor() {
    this.x = ground2.x + ground1.l / 2;
    this.y = random(ground1.y - 50, 180);
    this.w = random(50, spacing - 50);
    this.h = random(20, ground1.y - this.y);
    this.color = "blue";
  }
  show() {
    fill(this.color);
    rect(this.x, this.y, this.w, this.h);
  }
  move() {
    this.x -= groundSpeed;
    if (this.x + this.w <= 0) {
      this.x = ground2.x + 250;
      this.y = random(ground1.y - 50, 180);
      this.w = random(50, spacing - 50);
      this.h = random(20, ground1.y - this.y);
      this.color = "blue";
    }
    this.handleCollision();
  }
  handleCollision() {
    hit3 = collideRectRect(
      this.x,
      this.y,
      this.w,
      this.h,
      playerCharacter.x,
      playerCharacter.y,
      playerCharacter.size,
      playerCharacter.size
    );
    if (hit3) {
      this.color = "red";
      if (n < 1) playerCharacter.hitObstacle = true;
    } else {
      n = 0;
    }
  }
}

class Question {
  constructor() {
    this.factor1 = round(random(1, 12));
    this.factor2 = round(random(1, 12));
    this.product = this.factor1 * this.factor2;
    this.choices = [
      round(random(0, 150)),
      round(random(0, 150)),
      round(random(0, 150)),
      round(random(0, 150))
    ];
    this.correctChoice = round(random(0, 3));
    this.choices[this.correctChoice] = this.product;
  }

  show() {
    fill("cyan");
    rect(0, 300, width - 1, 150);
    textSize(20);
    fill(0);
    text(
      `What is ${this.factor1} x ${this.factor2} ? (Type the Number of your Choice)`,
      1,
      320
    );
    noFill();
    rect(50, 370, 35, 35);
    rect(150, 370, 35, 35);
    rect(250, 370, 35, 35);
    rect(350, 370, 35, 35);
    fill(0);
    text(`${this.choices[0]}`, 52, 395);
    text(`${this.choices[1]}`, 152, 395);
    text(`${this.choices[2]}`, 252, 395);
    text(`${this.choices[3]}`, 352, 395);
    fill(255);
    text(`1`, 62, 430);
    text(`2`, 162, 430);
    text(`3`, 262, 430);
    text(`4`, 362, 430);
  }
}
