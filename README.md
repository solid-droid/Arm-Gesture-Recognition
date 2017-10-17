# Arm-Gesture-Recognition for Prosthetic Hand
Arm gesture recognition using arduino and MPU6050.
The 4 motors are used for outputting the responses on the prosthetic fingers.
# Working
step 1: Fix the setup (at least the gyro) on your hand.    
Step 2: Input the 3 digit sequence by arm gestures.  
        The gestures can be up(8), down(2), turn-right(6), turn-left(4)    
step 3: Input one more random gesture to enter the sequence into the system.    
step 5: The micro controller  checks for a responce in the responce database.    
step 6: If found true the responce function will be called.    
# Error Protection
1. The 4 gesture(3 digits and a random one)  should be entered in under 5 seconds(can be modified)  
2. The 3 gesture sequence should have 3 different gestures to be accepted(can be modified)  
