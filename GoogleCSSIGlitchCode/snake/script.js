// Name any p5.js functions we use in the global so Glitch can recognize them.
/* global createCanvas colorMode HSB frameRate background width height stroke
   noFill noStroke text noLoop collideRectRect loop random fill keyCode rect UP_ARROW DOWN_ARROW RIGHT_ARROW LEFT_ARROW */

let backgroundColor, playerSnake, currentApple, score, followers;

function setup() {
  // Canvas & color settings
  createCanvas(400, 400);
  colorMode(HSB, 360, 100, 100);
  backgroundColor = 95;
  frameRate(12);
  playerSnake = new Snake();
  currentApple = new Apple();
  score = 0;
  followers = [];
  followers.push(playerSnake);
}

function draw() {
  background(backgroundColor);
  // The snake performs the following four methods:
  playerSnake.moveSelf();
  playerSnake.showSelf();
  playerSnake.checkCollisions();
  playerSnake.checkApples();
  // The apple needs fewer methods to show up on screen.
  currentApple.showSelf();
  // We put the score in its own function for readability.
  displayScore();
}

function displayScore() {
  fill(0);
  text(`Score: ${score}`, 20, 20);
}

class Snake {
  constructor() {
    this.size = 10;
    this.x = width / 2;
    this.y = height - 10;
    this.direction = "N";
    this.speed = 12;
  }

  moveSelf() {
    if (this.direction === "N") {
      this.y -= this.speed;
    } else if (this.direction === "S") {
      this.y += this.speed;
    } else if (this.direction === "E") {
      this.x += this.speed;
    } else if (this.direction === "W") {
      this.x -= this.speed;
    } else {
      console.log("Error: invalid direction");
    }
  }

  showSelf() {
    stroke(240, 100, 100);
    noFill();
    rect(this.x, this.y, this.size, this.size);
    noStroke();
  }

  checkApples() {
    if(collideRectRect(this.x, this.y, this.size, this.size, currentApple.x, currentApple.y, currentApple.size, currentApple.size)){
      currentApple = new Apple();
      score++;
      this.extendTail();
    }
  }

  checkCollisions() {
    if(this.x > width-this.size || this.x < 0)
      gameOver();
    if(this.y > height-this.size || this.y < 0)
      gameOver();
  }

  extendTail() {
    let follower = new Snake();
    followers.push(follower);
    for(let i = 1; i < followers.length; i++){
      if (this.direction === "N") {
        followers[i].y = followers[i-1].y + 10; 
      }// } else if (this.direction === "S") {
      //     this.y += this.speed;
      // } else if (this.direction === "E") {
      //     this.x += this.speed;
      // } else if (this.direction === "W") {
      //     this.x -= this.speed;
      // }
    }
   }
}

class Apple {
  constructor() {
    this.size = 10;
    this.x = random(width - this.size);
    this.y = random(height - this.size);
  }

  showSelf() {
    fill("red");
    rect(this.x, this.y, this.size, this.size);
    noFill();
  }
}

function keyPressed() {
  console.log("key pressed: ", keyCode);
  if (keyCode === UP_ARROW && playerSnake.direction != "S") {
    playerSnake.direction = "N";
  } else if (keyCode === DOWN_ARROW && playerSnake.direction != "N") {
    playerSnake.direction = "S";
  } else if (keyCode === RIGHT_ARROW && playerSnake.direction != "W") {
    playerSnake.direction = "E";
  } else if (keyCode === LEFT_ARROW && playerSnake.direction != "E") {
    playerSnake.direction = "W";
  } else if (keyCode === 32){
    restartGame();  
  }else {
    console.log("wrong key");
  }
}

function restartGame() {
  playerSnake = new Snake();
  currentApple = new Apple();
  score = 0;
  
  loop();
}

function gameOver() {
  //background('black');
  fill(0);
  text("GAME OVER!", 20, 45);
  noLoop();
}
