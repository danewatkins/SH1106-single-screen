# Single Screen Animation 


This code is for connecting a WEMOS D1 to a SH1106 1.3 SPI OLED Screen.\
![Fritzing of wemos to OLED](/images/single-screen.svg )
The OLED screen is black and white, that is the pixels are either on (white) or off (black). The code turns each individual pixel on and off. There is no anti-aliasing to smooth the edges of the drawing that you will find on laptops and phones. The animations are raw digital images where the code converts the drawings into a series of co-ordinates and switches the pixels on and off./

The code in this repo uses this animation made in photoshop.\ 
![black and white animation of a taxi](/images/taxi.gif )
When designing animation for the OLED screen you will need to make black and white drawings on a 128px(width) X 64px(height) field.\

Create the animation in a photoshop file so that each frame is on a new layer. In the image folder in this repo there is a psd file of the taxi. Download and look at this to see how the animation is prepared in photoshop.


- Download imagemagick https://imagemagick.org/script/download.php
and follow the instructions for your operating system. This is a free command line image editing tool.
