# Midterm Project

##Ideas
"Include 2 potential ideas for your midterm. Include pictures, videos, and drawings. If based on something already made document how yours will be different"
###Idea 1 - "Bop-it game"
Using a button, dial, tilt sensor, buzzer and lcd screen I want to create a version of the game bop-it. The LCD screen will tell the user whether to push, twist, or tilt. If the user does the wrong action or does't do the action within a time frame the game will be over. My concern is how I would encase this project.
Here is an example I found online: [Arduino Project - Bop-It Simulator](https://youtu.be/eTPN_UkYawU). This uses lights to tell the user what to do, I would use the lcd screen.

###Idea 2 - "Otto Robot"
I found the cutest robot, [Otto](https://youtu.be/eTPN_UkYawU), online. Its an open source project that has all the parts you need to download to make the robot. The issue with this project is that he uses a different Arduino board and is 3-d printed so I am not sure how I would go about making it for the Arduino I have or if I am better off getting a different Arduino. I would like to create it and add sound activation and feedback to him. So for example when you clap he starts to walk. I would also like to add some kind of feedback from him so maybe led lights or sound to indicate when he can't move forward when he has found an object in front of him. This would be a fin project to work with because I could add remote control to him, emotions, or gamify him as I learned more.

###Idea 3 - "Hand Held Game"
It could be fun to use a Nokia screen and create a little handheld game with something like pong.


##Final Idea - Robot
I am going to create a version of the Otto Robot. For the midterm I am going to develop his body with a microphone, ultrasonic sensor and an LED matrix.

###sketch
![Sketch](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/sketch.jpg "Sketch")

###Code Plan

####Explanation
Robot's LED nose will light up with there is something in front of the robot. When the user claps the robot will cycle through three facial expressions formed by an 8X8 LED matrix.

####Components
* Push Button
* LED (Yellow)
* Ultrasonic sensor
* Microphone
* 8x8 LED Matrix

####Pseudocode
* Push Button
  * If robot is off he will turn on. LED Mouth will turn on to show the robot is now on
  * If robot is on he will turn off.
* If the user claps the robot's facial expression (mouth) will change. The mouth will be created by a matrix of 8 LED lights.  
![Faces](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/faces.jpg "Faces")
  * There will be a counter that keeps track of what facial expression the robot currently has. Face 0, will be a smile
  * On first clap, the counter will go to 1. Face 1 will a surprised look.
  * On second clap, the counter will go to 2. Face 2 will be a frown.
  * On third clap counter will reset to 0, robot will display smile, and the loop will start over.
* If there is an object in front of the ultrasonic sensor the LED light will come on
  * LED will blink when something is 2 inches in front of the ultrasonic sensor
  * LED will stay stay on once object is within 1 inch.
