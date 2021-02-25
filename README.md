# Single Screen Animation 


This code is for connecting a WEMOS D1 to a SH1106 1.3 SPI OLED Screen.\
![Fritzing of wemos to OLED](/images/single-screen.svg )
The OLED screen is black and white, that is the pixels are either on (white) or off (black). The code turns each individual pixel on and off. There is no anti-aliasing to smooth the edges of the drawing that you will find on laptops and phones. The animations are raw digital images where the code converts the drawings into a series of co-ordinates and switches the pixels on and off over time.

## Animation
![black and white animation of a taxi](/images/taxi.gif )

The code in this repository uses this animation made in photoshop. When designing animation for the OLED screen you will need to make black and white drawings on a 128px(width) X 64px(height) field.

Create the animation in a photoshop file so that each frame is on a new layer. In the image folder in this repository there is a psd file of the taxi. Download and look at this to see how the animation is prepared in photoshop.

## Convert Animation into Code
Download imagemagick https://imagemagick.org/script/download.php
and follow the instructions for your operating system. This is a free command line image editing tool.

- Open the directory with the PSD in your terminal. 
If you do not know how to do this then this page shows how to [Open a Command Prompt or Terminal to a Specific Folder in Windows, Mac or Linux](https://www.groovypost.com/howto/open-command-window-terminal-window-specific-folder-windows-mac-linux/)

- convert photoshop layers to png  
`convert puke.psd -coalesce puke%d.png`
This command converts all the layers in your photoshop file to an individual png

- convert png layers to xbm  
`mogrify -resize 128x64 +dither -format xbm *.png`
This command converts all the png files to an XBM file, which is C source code. It converts the pixels into co-ordinates

- convert xbm to file  
`cat *.xbm | sed s/static/const/ | sed s/=/PROGMEM=/  > taxi.h`
This command aggregates all the XBM files into one file which can be used in Arduino.

You will need a text editor in order to change the code. I use Atom
[Download Atom text editor](https://atom.io/)

- open taxi.h (or whatever you have titled your file) in Atom

- open the search and replace `Find > Find in Buffer`
