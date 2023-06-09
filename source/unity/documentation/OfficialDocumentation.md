# Paper Plane Tools
paperplanetools@gmail.com

### OpenCV + Unity package, installation and running notes
1. As OpenCV bridge script files require "unsafe" compiler option for C#, you'll also need to copy OpenCV+Unity/smcs.rsp and
   OpenCV+Unity/gmcs.rsp files into your root Assets folder. More info about the matter can be found here
   http://answers.unity3d.com/questions/804103/how-to-enable-unsafe-and-use-pointers.html
2. [Optional] Package content from OpenCV+Unity/Plugins folder must be placed to your project's root Plugins directory (Assets/Plugins)
   This is described in general Unity documentation, however, on our tests the step was not necessary
3. Re-start Unity Editor or Reimport All assets
4. [Optional] Add all scenes to your build. For more information see 'Lobby scene' section of this documentation.
5. Open Lobby scene (OpenCV+Unity/Demo/Lobby/LobbyScene) or any other demo scene and run

### Demo scenes:
Package contains three demo scene to illustrate OpenCV usage, they are located in the OpenCV+Unity/Demo directory:
1. "Lobby" - general demo scene that presents all the scene and allow to test each other demo module withing a click
2. "Grayscale" - simple texture loading example with further "black & white" filter applied via OpenCV
3. "Identifiy_Contours_by_Shape" - loads a texture with various geometrical shapes and identifies them via OpenCV
4. "LiveSketch_WebCam" - realtime webcam video fetching with OpenCV-based post-processing
5. "Face_Detector" - realtime face detector with face landmarks construction, by default detects face rects only, but it provides
					 additional instructions about how to download free public pre-trained shape predictor from DLib to get
					 landmarks detector working, just run it in the Unity Editor and follow onscreen instructions
6. "Marker Detector" - detect markers based on ArUco library
7. "Document_Scanner" - a complete scene that demonstrates technoque used in mobile paper scanners
8. "Face_Recognizer" - a simple face recognition example that uses OpenCV Contrib/Face module and pre-trained recognizer to
					   distinguish between Hollywood stars on a sample photo. Scene code contains wide comment blocks that
					   explain the concepts and give some instructions
9. "Object tracking" - a sample scene that allows to draw a rect over webcam stream and track selected object further movements
	
### Lobby scene:
In order to make Lobby scene works add all scenes to your build.
To do so navigate to File -> Building Settings that drag all demo scenes to 'Scenes in build' input.


### Troubleshooting:
1. Compiler error stating "-unsafe" option is required - please refer to the #1 of the "installation" section stated above
2. Run-time error "SocketException: An attempt was made to access a socket in a way forbidden by its access permissions."
   appers upon "Play" in the Unity editor - simply re-start Unity Editor
3. If you experience errors on Android device try to build Unity project with il2cpp instead of Mono
4. Exception when trying to open demeo from Lobby Scene. Please add all scenes to your build. 
   For more information see 'Lobby scene' section of this documentation.

### Building iOS
After createing Xcode project 
1. Add 'Privacy - Camera Usage Description' key into Info.plist if using camera. Related topic http://stackoverflow.com/a/39488067
2. Set 'Enable C++ Runtime Types' to 'Yes' in your target 'Build Settings'
3. Don't forget to sign your product (Target -> General -> Signing)

Feel free to contact us should you have any issues or questions regarding package, contact e-mail is stated on top of this document.
