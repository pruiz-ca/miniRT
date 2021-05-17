# miniRT
A raytracer made in C

## Features
- Multithreading
- Variable resolution
- Objects: spheres, cylinders, triangles, squares, planes
- Multiple spot lights
- Ambient lighting
- Multicamera
- Camera movement and rotation using keyboard
- Camera rotation with right click
- Camera filters: b&w, sepia, negative, gamma
- Object selection and movement
- Save bmp image of any scene
- Scene map error handling

## How to use
1. Run make in the root directory
2. Write your scene.rt file or use any of the already available test scenes in /scenes
3. Run ./miniRT yourscene.rt

## Writing a scene description file
- It can have any name but it must end in ".rt"
- Each element can be separated by one or more spaces/tabs
- Each element can be separated by one or more linebreaks
- Elements defined by a capital letter can only be declared once in the scene
- Each element first's information is the type identifier followed by all specific information for each object in the following strict order:

	- Resolution:
		`R 1920 1080`
		- id : R
		- x render size
 		- y render size

	- Ambient lighting:
		`A 0.2 255,255,255`
		- id: A
		- ambient lighting in range [0.0 - 1.0]
		- R,G,B colors in range [0-255]

	- Camera:
		`c -50,0,20 0,0,1 70`
		- id: c
		- x,y,z view point coordinates
		- 3d normalized orientation vector in range [-1, 1]
		- FOV in range [0 - 180]

	- Light spot:
		`l -40,50,0 0.6 10.0.255`
		- id: l
		- x,y,z light point coordinates
		- light brighness ratio in range [0.0 - 1.0]
		- R,G,B colors in range [0-255]

	- Sphere:
		`sp 0,0,20 12.6 10,0,255`
		- id: sp
		- x,y,z sphere center coordinates
		- sphere diameter
		- R,G,B colors in range [0-255]

	- Plane:
		`pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225`
		- id: pl
		- x,y,z coordinates
		- 3d normalized orientation vector in range [-1,1]
		- R,G,B colors in range [0-255]

	- Square:
		`sq 0.0,0.0,20.6 1.0,0.0,0.0 12.6 255,0,255`
		- id: sq
		- x,y,z coordinates of the square center: 0.0,0.0,20.6
		- 3d normalized orientation vector in range [-1,1]
		- side size: 12.6
		- R,G,B colors in range [0-255]

	- Cylinder:
		`cy 50.0,0.0,20.6 0.0,0.0,1.0 10,0,255 14.2 21.42`
		- id: cy
		- x,y,z coordinates
		- 3d normalized orientation vector in range [-1,1]
		- diameter
		- height
		- R,G,B colors in range [0-255]

	- Triangle:
		`tr 10.0,20.0,10.0 10.0,10.0,20.0 20.0,10.0,10.0 0,0,255`
		- id: tr
		- x,y,z coordinates of the first point
		- x,y,z coordinates of the second point
		- x,y,z coordinates of the third point
		- R,G,B colors in range [0-255]


## Scene file example
```
R	1000 1000

A	0.2	255,255,255

c	0,50,-50 0,-0.3,1 90
c	-20,0,-0 0.18,0,1 90
c	-20,50,-10 0.16,-0.4,1 90

l	0,50,50 1 255,255,255

sp	0,0,100 30 255,255,0
sp	0,10,150 20 0,255,0
sp	30,20,90 20 0,255,255

pl	0,-50,0 0,1,0 124,124,140
```
