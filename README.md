# IoT Development Board 1.0, using 4051 @TEchnomate Edubotics Pvt Ltd.

> USING 4051 MuX

4051 multiplexer can used in NodeMCU to extend it's number of Analog pins. Currently there's only one analogPin A0. 
This is a cheap way to get more analog pins out of one by changing the bit values like:

0,0,0 - X0
0,0,1 - X1
0,1,0 - X2 and so on..

It's much better to use a cheaper solution than to buy a pin extender for over 500RS when an IC is available for just 30-40rs.
Using this IC, the nodeMCU projects can be taken into next level, whether HOME Automation with Advanced Sensing Facilities or An Well Implemented Agricultural Solution, because most of sensors used in it reads Analog Data!

With the 4051 you can connect up to 8 analog devices to the single analog pin on your ESP8266, it also uses 3 digital pins (A small price to pay).

## Table of Contents

- [Connections](#connections)
- [Using the IC with Node MCU](#icuse)
- [Workshop Section](#workshop)
                    - [installing the required libraries and dependencies](#workshop)
                    
                    

## Connections

The below picture shows the IC and how it is to be connected.

![4051 IC](https://cdn.instructables.com/F86/2BIX/IZ6BLLJZ/F862BIXIZ6BLLJZ.LARGE.jpg)

The pins to be connected are:

D4 -> S0 (A)<br>
D3 -> S1 (B)<br>
D2 -> S2 (C)<br>
A0 -> Common<br>
3.3v -> VCC<br>
G -> GND<br>
G -> Inhibit<br>
G -> VEE<br>

Obviously, the digital pins used can be modified accordingly. You will find the basic code to use this in ()

