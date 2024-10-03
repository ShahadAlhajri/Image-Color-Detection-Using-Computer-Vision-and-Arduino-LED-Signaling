import cv2
import serial
import numpy as np
import time

try:
    # Load the image
    image = cv2.imread('C:\\Users\\shaha\\Downloads\\greeno.png')
    cv2.imshow('image', image)
    cv2.waitKey(0)
    # Convert the image to RGB
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    # Calculate the percentage of red, green, blue, and yellow
    red_mask = np.all([image_rgb[:, :, 0] > 150, image_rgb[:, :, 1] < 100, image_rgb[:, :, 2] < 100], axis=0)
    green_mask = np.all([image_rgb[:, :, 1] > 150, image_rgb[:, :, 0] < 100, image_rgb[:, :, 2] < 100], axis=0)
    blue_mask = np.all([image_rgb[:, :, 2] > 150, image_rgb[:, :, 0] < 100, image_rgb[:, :, 1] < 100], axis=0)
    yellow_mask = np.all([image_rgb[:, :, 0] > 150, image_rgb[:, :, 1] > 150, image_rgb[:, :, 2] < 100], axis=0)

    red_percentage = np.sum(red_mask) / red_mask.size
    green_percentage = np.sum(green_mask) / green_mask.size
    blue_percentage = np.sum(blue_mask) / blue_mask.size
    yellow_percentage = np.sum(yellow_mask) / yellow_mask.size

    # Determine the dominant color
    dominant_color = max(red_percentage, green_percentage, blue_percentage, yellow_percentage)

    # Send the dominant color to Arduino
    # Initialize and use the serial communication within a context manager
    with serial.Serial('COM7', 9600, timeout=1) as arduino:
        # Send the dominant color to Arduino
        if dominant_color == red_percentage:
            arduino.write(b'R')
            time.sleep(2)
        elif dominant_color == green_percentage:
            arduino.write(b'G')
            time.sleep(2)
        elif dominant_color == blue_percentage:
            arduino.write(b'B')
            time.sleep(2)
        elif dominant_color == yellow_percentage:
            arduino.write(b'Y')
            time.sleep(2)

    # No need to explicitly close the serial port here, as it will be closed automatically
    print('shahad')

except Exception as e:
    print(f"An error occurred: {e}")