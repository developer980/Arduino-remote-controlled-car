# Arduino-remote-controlled-car

- A remote controlled car programmed with C++ embedded with an Arduino board.
- The car uses the tank principle to move and change directions.
- It also uses a proximity sensor to detect the distance to the upcoming obstacles. If the distance is within 40 cm, the car stops.
- If an object appears infront of the car within a distance much smaller than 40 cm, the car will move backwards to avoid the collision.

## Components used for the car:
- 1 Arduino MEGA 2560 for the car automation
- 1 L298N double H bridge for controlling the speed and direction of the wheels.
- 2 DC geared motors with a ratio of 1:48
- 1 NRF24L01+ wireless module for receiving the signals from the remote
- 1 Ultrasonic sensor for monitoring the distance between the car and the obstacle located in front of it

## Components used for the remote:
- 1 Arduino ONE board for the remote automation
- 1 NRF24L01+ wireless module for sending signals to the car
- 2 push buttons for remote controlls
- 2 resistors to ensure the quality of the connection between the buttons and the board

  ![WhatsApp Image 2023-11-30 at 20 58 01_a68c270f](https://github.com/developer980/Arduino-remote-controlled-car/assets/91996303/2af79bed-f0d7-49e2-a415-66e13a6a36c9)
  
![WhatsApp Image 2023-11-30 at 20 58 02_16606801](https://github.com/developer980/Arduino-remote-controlled-car/assets/91996303/fac69afe-548d-46fa-b10f-fff7564a5300)

## A demonstration of the car can be found in the "Remote car video.mp4" file in the repo.
