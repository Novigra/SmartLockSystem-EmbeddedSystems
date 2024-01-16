# Why do we need a smart lock system?

As the world shifts to a more smart and IoT environment, we see smart vehicles and smart TVs, but rarely do we see smart lock systems, especially in households. It is very easy to break into someone's house as the mechanical design of a keyhole is predictable, so we need to embrace technology and live in a safe environment.

# Features

- A screen to show your input while entering your password and show you if you entered the right password or not.
- A keypad that allows you to enter your password or update it.
- A buzzer that will play a different sound depending on the user’s action.
- A firebase database that shows you if someone interacted with the component and when they did.

# Hardware Components

- LCD 16x2
- Piezo Buzzer
- Membrane Keypad 4x3
- Arduino Uno Microcontroller

## LCD 16x2

I used an LCD for visual representation, so you can see your input and what functionalities you can do. I also used a 16x2 LCD, as it is enough for our use case.

- 16 → Columns
- 2 → Rows
- It also has a nice feature where, if you use it in the dark, you can connect the anode and cathode to light up the screen and control the brightness.
- You can use D0 to D7 8-bit, but in this project, I used a 4-bit interface to avoid connecting so many cables.
- The LCD shows the current password **(of course, if it was a product, you don’t show the password, and it is just for debugging)**, and when the user presses on the membrane keypad, a number shows on the screen.
- It also shows whether you’re about to enter the password or update it when pressing ‘#’ on the membrane keypad.

## Piezo Buzzer

The buzzer is used for sound representation; it buzzes at different frequencies depending on the user's action.

The buzzer plays different sounds at different rates when:

- The user enters the right password.
- The user enters the wrong password.
- The user updates the password.

## Membrane Keypad 4x3

Of course, we need a keypad for user input; a 4x3 keypad will suffice.

- 4 → Rows
- 3 → Columns

## Arduino Uno Microcontroller

Lastly, we need a brain to process all of this, and an Arduino Uno will do the job.

Something that you may find trouble with while using the Arduino Uno is that the digital pins will be fully used, so to tackle this problem, you will have to use the analog pins as digital.

# Circuit

![Screenshot2](https://github.com/Novigra/SmartLockSystem-EmbeddedSystems/assets/59344266/95f7063f-84bc-48a8-984a-83bda7156a53)


# Security

Having a password is not enough; you also need to keep track of the machine's activity and be aware if someone malicious uses it and tries to break in.

A great way to do that is to create a log system that keeps track of user input. The complexity of such a system will depend on the programmer and how far you are willing to take it. For example, do you want to log if the user enters the password right or wrong or updates it? Or do you want to log every single input? You have to keep in mind that if you create a log system, it must be readable.

![IMG](https://github.com/Novigra/SmartLockSystem-EmbeddedSystems/assets/59344266/afb7cd0f-885b-40cd-9287-33b5f4e13e07)
