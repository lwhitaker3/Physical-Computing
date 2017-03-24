# Midterm Project

##Ideas
"Include 2 potential ideas for your midterm. Include pictures, videos, and drawings. If based on something already made document how yours will be different"
###Idea 1 - "Bop-it game"
Using a button, dial, tilt sensor, buzzer and lcd screen I want to create a version of the game bop-it. The LCD screen will tell the user whether to push, twist, or tilt. If the user does the wrong action or does't do the action within a time frame the game will be over. My concern is how I would encase this project.
Here is an example I found online: [Arduino Project - Bop-It Simulator](https://youtu.be/eTPN_UkYawU). This uses lights to tell the user what to do, I would use the lcd screen.

###Idea 2 - "Otto Robot"
I found the cutest robot, [Otto](https://youtu.be/yC6u0AjI76U), online. Its an open source project that has all the parts you need to download to make the robot. The issue with this project is that he uses a different Arduino board and is 3-d printed so I am not sure how I would go about making it for the Arduino I have or if I am better off getting a different Arduino. I would like to create it and add sound activation and feedback to him. So for example when you clap he starts to walk. I would also like to add some kind of feedback from him so maybe led lights or sound to indicate when he can't move forward when he has found an object in front of him. This would be a fin project to work with because I could add remote control to him, emotions, or gamify him as I learned more.

###Idea 3 - "Hand Held Game"
It could be fun to use a Nokia screen and create a little handheld game with something like pong.


##Final Idea - Robot
I am going to create a version of the Otto Robot. For the midterm I am going to develop his body with a microphone, ultrasonic sensor and an LED matrix.

###Sketch
![Sketch](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/sketch.jpg "Sketch")

###Code Plan

####Explanation
Robot's LED nose will light up with there is something in front of the robot. When the user claps the robot will cycle through three facial expressions formed by an 8X8 LED matrix.

####Components
* Push Button
* LED (Yellow)
* Ultrasonic sensor
* Microphone
* 8x8 LED Matrix (For this project: 1 red led, 1 blue led, 1 yellow led)

####Pseudocode
* Push Button
  * If robot is off he will turn on. LED Mouth will turn on to show the robot is now on
  * If robot is on he will turn off.
* If the user double claps the robot's facial expression (mouth) will change. The mouth will be created by a matrix of 8 LED lights. For the first version of the project the led matrix will be represented by 3 led lights.  
![Faces](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/images/faces.jpg "Faces")
  * There will be a counter that keeps track of what facial expression the robot currently has. Face 0, will be a smile
  * On first clap, the counter will go to 1. Face 1 will a surprised look.
  * On second clap, the counter will go to 2. Face 2 will be a frown.
  * On third clap counter will reset to 0, robot will display smile, and the loop will start over.
* If there is an object in front of the ultrasonic sensor the LED light will come on
  * LED will blink when something is 2 inches in front of the ultrasonic sensor
  * LED will stay stay on once object is within 1 inch.

####Possible Addition
* Add a speaker so robot can "talk". He would say prerecorded mp3 files.

##Putting it Together

###1. Learning how the sensors worked
![Initial](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/images/initial.jpg "Initial Board")
I began the project with the Ping Ultrasonic Sensor and the Electret Mic with 4 LED lights. I created very simple sketches that gathered data from these two sensors and outputted it to the LED Lights.

The microphone measures the volume and when it is over 1 volt the LED light that is currently on changes to the next light.
See the video [here](https://youtu.be/Mw7cgnJKZ80)


The ultrasonic sensor was set up to blink as an object was within 8 cm, blink faster when it got to 6, and stay on constantly when it got to 4 cm.
See the video [here](https://youtu.be/cZ69LhATB1o)

###2. Making a Box to Put it in
![Box](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/images/building_box.jpg "Box")
Then I cut a box out of cardboard and painted it in order to create a robot head to encase the Arduino and breadboard in.

###3. Adding the Piezo Buzzer
![Box](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/images/building.jpg "Box")
I added a piezo buzzer so the robot would give more feedback to the user. Initially the buzzer just came on a stayed on while an object was within 4cm.

###4. Putting it in the Box
![Box](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/images/putting_in_box.jpg "Box")
This was a challenge. There were a lot of wires, and not a lot of space. I hadn't built the case taking into account the long plastic ends on the wires, so that made it challenging to pack it all in.

###5. Refining the Code
![Box](https://github.com/lwhitaker3/Physical-Computing/blob/master/Midterm/images/final_box.jpg "Box")

I added a double clap to the changing LED lights - this means there is more control over the interaction and a loud noise alone from another source won't trigger the reaction.

I added notes to the piezo buzzer so it made a little robotic sound instead of a monotonous noise. It also only plays 1 time when there is an object in front of it, instead of staying on the whole time.

I removed the delay from the Ping Sensor code so it could all work together without interrupting other functions.

My files where i was testing code are in the practice folder. The final code is in the final folder.
