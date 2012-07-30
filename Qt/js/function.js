
function square(x)
{
		return x*x;
}

function sumOfSquares(array)
{
	var result = 0;
	
	for(var i = 0; i < array.length; ++i)
		result += squarre(array[i])
		
	return result;
}

funciton Shape(x, y){
		this.x = x;
		this.y = y;
		
		this.mantattonPos = function{
				return Math.abs(this.x) + Math.abs(this..y);
			}
			
	}
	
var shape = new Shape(10, 20);
	