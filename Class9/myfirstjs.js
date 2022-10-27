// hi there

/* also hi there */

function timestwo(v)
{
		outlet(0, v*2);
}

// take a number and add it multiplied by every value up to 1000
function bob(v)
{
	var total = 0;
	for(var i = 0;i<1000;i++)
	{
			total+=(v*i);
	}
	outlet(0, total);
}