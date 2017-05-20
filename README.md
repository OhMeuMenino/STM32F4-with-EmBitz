# STM32F4 with EmBitz  
![EmBitz](https://github.com/OhMeuMenino/STM32F4-with-EmBitz/blob/master/images/EmBitz.png)

This repo is a guide to start developing projects with STM32F3 Discovery board and EmBitz IDE.
Using the standart libraries, there ares examples how to configure and use the peripherals in a easy way. Probably this examples could be applied to others ARM microcontrolers.
Enjoy it :)

## Contents

* [StartProject](./StartProject) - Start project for STM32F429ZI
* [TimerCounter](./TimerCounter) - Timer configuration
* [TimerNVIC](./TimerNVIC) - Timer configuration and interrupt

## Pre-requisites 
* Install EmBitz from the official page https://www.embitz.org/
* STM32F4 Discovery board (or other stm32F4 microcontroller)

## Getting Started

### New project

```
If you want, you can just use the StartProject and skip this step
```

*File-> New Project -> choose STM32F429ZI* (the microcontroller used on discovery board).

Make sure you select the Standart Peripherals Library!

### Write code

In the project tree *Sources -> src* you will find the main.c 

### Write on microcontroller

When everything is done, you can click on debug button (top bar) to compile the code and programing the microncontroller.

![Write and run](https://github.com/OhMeuMenino/STM32F4-with-EmBitz/blob/master/images/write.png)

If is everything ok EmBitz will open a new file (in assembely), ignore it for now.

Click on Continue and you will see your code working on.

## Contributing

Feel free to pull request 

## Authors

* **Daniel Oliveira** - [OhMeuMenino](https://github.com/OhMeuMenino)
