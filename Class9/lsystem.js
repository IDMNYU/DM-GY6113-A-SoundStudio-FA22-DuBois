
var thestring = "A";

var therules = [["A", "B"], ["B", "AB+CB"], ["C", "A-C"]];

outlets = 2;

var numprods = 10;

for(var i = 0;i<numprods;i++)
{
		var outstring = "";
		
		for(var j = 0;j<thestring.length;j++)
		{
			var ismatch = 0;
				for(var k =0;k<therules.length;k++)
				{
					if(thestring.charAt(j)==therules[k][0])
					{
							ismatch = 1;
							outstring+=therules[k][1];
					}
				}
				if(ismatch==0) outstring+=thestring.charAt(j);
			
		}
		
		
		outlet(1, outstring);
		thestring = outstring;
}

var iptr = 0;

function bang()
{
	outlet(0, thestring.charAt(iptr));
	iptr = (iptr+1) % thestring.length;
}