
# Image Color Detection Using Computer Vision and Arduino LED Signaling



## Overview



This project develops an interactive system that uses computer vision to detect dominant colors in images and displays the results with Arduino-controlled LED lights. Designed for children, this system makes learning about primary colors fun and engaging. As the system analyzes an image, the corresponding LED light illuminates to represent the most prevalent color, enhancing the educational experience.



## Objectives



- **Color Detection:** Utilize computer vision techniques to identify and analyze the primary colors in an image.

- **Interactive Learning:** Create a hands-on experience for children to learn about colors in a playful manner.

- **Visual Feedback:** Use LED lights to provide immediate visual representation of the detected dominant color.



## Methodology



1. **Image Processing:** The system uses Python and OpenCV to load and process the image, converting it to RGB format and calculating the percentages of primary colors (red, green, blue, yellow).

2. **Arduino Control:** The processed data is sent to an Arduino board via serial communication, which activates the appropriate LED based on the detected dominant color.

3. **User Interaction:** Children can upload their images and see the results in real-time, fostering curiosity and learning about color composition.

## Arduino Components


## Schematic Diagram and Connections


## Technical Details



- **Programming Languages:** Python for image analysis and Arduino for LED control.

- **Image Processing Library:** OpenCV for analyzing color composition.

- **Microcontroller:** Arduino to control LED lights based on the color detected.



## Conclusion



The Image Color Detection system combines technology with education, providing children with an innovative tool to explore and understand color dynamics. By engaging with this system, children not only learn about primary colors but also develop an interest in technology and programming.


