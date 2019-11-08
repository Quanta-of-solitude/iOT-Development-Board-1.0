# IoT Development Board 1.0, using 4051 @Technomate Edubotics Pvt Ltd.

> USING 4051 MuX

4051 multiplexer can used in NodeMCU to extend it's number of Analog pins. Currently there's only one analogPin A0. 
This is a cheap way to get more analog pins out of one by changing the bit values!


It's much better to use a cheaper solution than to buy a pin extender for over 500RS when an IC is available for just 30-40rs.
Using this IC, the nodeMCU projects can be taken into next level, whether HOME Automation with Advanced Sensing Facilities or An Well Implemented Agricultural Solution, because most of sensors used in it reads Analog Data!

With the 4051 you can connect up to 8 analog devices to the single analog pin on your ESP8266, it also uses 3 digital pins (A small price to pay).

## Table of Contents

- [Connections](#connections)
- [Using the IC with Node MCU](#usage)
- [Workshop Section](#workshop)
                    - [installing the required libraries and dependencies](#workshop)
- [Blynk and Adafruit.io](#accounts)
                    
                    

## Connections

The below picture shows the IC and how it is to be connected.

![4051 IC](https://cdn.instructables.com/F86/2BIX/IZ6BLLJZ/F862BIXIZ6BLLJZ.LARGE.jpg)
<br><br>
The pins to be connected are:

D4 -> S0 (A)<br>
D3 -> S1 (B)<br>
D2 -> S2 (C)<br>
A0 -> Common<br>
3.3v -> VCC<br>
G -> GND<br>
G -> Inhibit<br>
G -> VEE<br>

Obviously, the digital pins used can be modified accordingly. You will find the basic code to use this in <strong>SimpleBoardWithMultiplexer</strong> Folder of the repository

A proper guide can be found in [here](https://www.instructables.com/id/How-to-Use-Multiple-Analog-Sensors-on-Your-ESP8266/)<br>

## Usage

```
#define MUX_A D4
#define MUX_B D3
#define MUX_C D2

#define ANALOG_INPUT A0



void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

```

So here the changeMux Function is doing the trick!

0,0,0 - X0<br>
0,0,1 - X1<br>
0,1,0 - X2 and so on..
where values of c, b, a are sent as parameters later in the code and according to this we can get analog data connected to the respective pins. The X0 - X7 configurations will kind of look like this:

0,0,0 - X0<br>
0,0,1 - X1<br>
0,1,0 - X2<br>
0,1,1 - X3<br>
1,0,0 - X4<br>
1,0,1 - X5<br>
1,1,0 - X6<br>
1,1,1 - X7<br>
<br>

## Workshop

This section is for the workshop of IOT systems.
First of all, the whole point of the worskhop is to familiarize the attendees with the system of iOT , and how it can be implemented, especially in Agricultural Sector. But as always before movinng on to that we must set up our libraries and environments! This is a crucial Step..<br>

Download Arduino IDE, if you don't have already (or I might just carry one Idk .-.)
- [Download IDE](https://www.dropbox.com/s/j3af430bg6cykll/arduino-1.8.10-windows.exe?dl=1)

if the previous step was already done then skip that and read the below,

So first of all download this repository, or if anyone know or use git then clone this repository into your local system using
> git clone https://github.com/Quanta-of-solitude/iOT-Development-Board-1.0.git

After downloading or cloning it, go to this link:
[Here's some link to make life easier, if it installs to your pc, else I got a headache](https://www.tinyurl.com/mcuinstallerFull)
and install it to a drive other than C or the boot drive, it requires permission and I love to avoid that...
After installation, you will find a file with name InstallerX.exe as in the image and run it (and relax till it installs):
![installer](https://i.ibb.co/vvTBpdg/installer-X.png)<br><br>

If it successfully installs then HURRAH! if not, you have missing dependencies, likely:
- [WinRaR](https://www.win-rar.com/postdownload.html?&L=0)
- [vcredist](https://www.microsoft.com/en-in/download/confirmation.aspx?id=48145)

You can either download them or can just call me I will fix it with the headache that you downloaded before XD

So, once this is done open up your arduino 1.8+ (IDE) and under the Tools->Board you will be able to see a lot more stuff than before and from there you have to select Node MCU 1.0 (ESP - 12 E Module)
![this is how it appears](https://i.ibb.co/Lpjtrxh/nodemcupacks.jpg)

<br><br>So, if this appears we are <strong>SET!</strong> Incase of any problem, do not hesitate to call me .-.

<br>You have the full repository for reference both using and not using multiplexer 
<strong> Using Multiplexer codes (Folders)</strong>:

  - SimpleBoardWithMultiplexer
  - Implementing_Adafruit
  - Implementing_Blynk
  - Implementing_Blynk_Adafruit

<strong>For without Multiplexer is in noPlexer Folder </strong>

<strong> For the Workshop, there's the WORKSHOP Folder. </strong>

> Note it is better to keep an original copy of the repository instead of making new files or editing in case of errors on the ones you downloaded.


## Accounts

Furhter more to use Blynk and Adafruit You have to setup your accounts. (more work XD)<br>

<strong>For Blynk: </strong>

Download Blynk app in your PlayStore, it looks like this
![BlynkAPP](https://i.ibb.co/WtHhdhC/Blynk.png)
<br>
Register yourself in the app, Create a New Project with options as: 

- Project Name Whatever you want!
- Choose Device->NodeMCU
- Connection Type-> WiFi

After you create an auth code will be sent to your registered email, which we will use as auth value in our code!

```
char* auth = "Here will be your auth code from mail";

```
and we are good to use BLYNK! :)
<br>
<strong>For Adafruit: </strong>

Go to https://io.adafruit.com/ and click on GET STARTED FOR FREE to signup!
After a proper signup, login using your credentials.  
Now, on the right top we will find ![AIO Key](https://i.ibb.co/RbNs6Tn/AIO.png) ,click on it to get your auth credentials.<br>
We need the user name and key from there as it will be used in the code.<br>
![usernamekey](https://i.ibb.co/x8qwjym/authaio.jpg)
<br>
We use this in the following section of our code:

```
#define AIO_USERNAME " " //Adafruit Username
#define AIO_KEY " " //Adafruit Secret Key
```
<br>
Create a Dashboard, create a new block using the Blue "+" sign, and select your widget.
After that you will have to create a new feed. This is an important step. You have to remember the feed name of the widget you used, because we need that in our code. Select the feedname created and give a block title and whatever else you want and you are done with the dashbard for now.<br>

![food](https://i.ibb.co/xMXrVgc/feed.png)

We use that feedname in this section of our code: <br>

```
Adafruit_MQTT_Publish Data = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME"/feeds/This is here the feed name will be");
```




<br>

> Hope this all helps in the learning, I am a noob and learning myself. Thanks! 
