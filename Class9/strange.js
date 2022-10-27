// strange.js
//
// generate strange attractors according to random/evolved coefficients
//
// attractor is generated via:
//
//	X = sin(A*y)-z*cos(B*x)
//	Y = z*sin(C*x)-cos(D*y)
//	Z = E*sin(x)
//

var x, y, z;
var A, B, C, D, E;

function init()
{
		x = 0;
		y = 0;
		z = 0;
		A = Math.random()*10.-5;
		B = Math.random()*10.-5;
		C = Math.random()*10.-5;
		D = Math.random()*10.-5;
		E = Math.random()*10.-5;
}

function bang()
{
	var newx = Math.sin(A*y)-z*Math.cos(B*x)
	var newy = z*Math.sin(C*x)-Math.cos(D*y)
	var newz = E*Math.sin(x)
	
	outlet(0, newx, newy, newz);
	x = newx;
	y = newy;
	z = newz;
	
}