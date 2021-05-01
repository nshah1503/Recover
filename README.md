# Recover-
Recover is a C program that from a .raw files recovers jpeg images.
JPEG files have a certain pattern that differentiate each image from other. Every JPEG file starts with a 4 digit hexadecimal code. What this program does is finds that unique hexadecimal code and traverses unitil it finds next code like that, which means current image has been traversed and new image has been started.

A .raw file containing 50+ images in bits is used as a sample.

