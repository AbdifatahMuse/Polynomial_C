#include <Polynomial.h>
#include <stdlib.h>
#include <math.h>

bool    Polynomial_Set(Polynomial* const P, const uint8_t D, const int64_t* const C){
	//copy degree
	P.Degree = D;
	P->Coeff = malloc(D*sizeof(int64_t));
	if (P->Coeff != null){
		//copy coefficients
		for( int i = 0; i < D; i++)
		{
			//TODO Error? c is a pointer to an array may need to dereference
			P->Coeff[i] == *C[i];
		}
		//TODO false
		return true;
	}
	else{
		return false;
	}
	
}

bool    Polynomial_Copy(Polynomial* const Target, const Polynomial* const Source){
	return Polynomial_Set(Target, Source.Degree, Source->Coeff);
	
	//copy degree
	//Target->Degree = Source->Degree;
	//realloc(Target->Coeff, (Source->Degree)*sizeof(int64_t));
	//set
	//for (int i = 0; i < Source->Degree; i++)
	//{
		//Target->Coeff[i] = Source->Coeff[i];
	//}
	
	//TODO false
}

bool    Polynomial_Equals(const Polynomial* const Left, const Polynomial* const Right){
	if(Left.Degree == Right.Degree){
		for(int i = 0; i < Left.Degree; i++){
			if(Left->Coeff[i] != Right->Coeff[i]){
				return false;
			}
		}
	}
	else{
		return false;
	}
}

int64_t Polynomial_EvaluateAt(const Polynomial* const P, const int64_t X){
	//make sure polynomial is initialized properly
	if(P.Degree > 0){
		int64_t sum = 0;
		for(int i = 0; i < P.Degree; i++){
			//TODO powers correctly
			sum += P->Coeff[i] * pow(X, i);
		}
		return sum;
	}
	else{
		return 0;
	}
}

bool    Polynomial_Scale(Polynomial* const Scaled, const Polynomial* const Source, const int64_t K){
	//TODO check to be initialized
	Scaled.Degree = Source.Degree;
	realloc(Scaled->Coeff, (Scaled.Degree) * sizeof(int64_t));
	if (Scaled->Coeff != null){
		for (int i = 0; i < Source.Degree; i++){
			Scaled->Coeff[i] = Source->Coeff[i] * K;
		}
		return true;
	}
	return false;
}

//TODO false
bool    Polynomial_Add(Polynomial* const Sum, const Polynomial* const Left, const Polynomial* const Right){

	int degreeEquality = 0;
	if (Left.Degree > Right.Degree){
		Sum.Degree = Left.Degree;
		degreeEquality = 1;
	}
	else if (Left.Degree < Right.Degree){
		Sum.Degree = Right.Degree;
		degreeEquality = 2;
	}
	else{
		Sum.Degree = Left.Degree;
	}
	//reallocate size of sum array to be as large as needed
	realloc(Sum->Coeff, (Sum.Degree) * sizeof(int64_t));
	
	if (Sum->Coeff != null){
		for (int i = 0; i < Sum.Degree; i++){
			if (i + 1 <= Left.Degree && i + 1 <==Right.Degree){
			Sum->Coeff[i] = Left->Coeff[i] + Right->Coeff[i];
			}
			else if (i + 1 > Left.Degree){
				Sum->Coeff[i] = Right->Coeff[i];
			}
			else{
				Sum->Coeff[i] = Left->Coeff[i];
			}
		
		}
		return true;
	}
	
	return false;
	}	

	
bool    Polynomial_Subtract(Polynomial* const Diff, const Polynomial* const Left, const Polynomial* const Right){
	//check to see which is bigger
	if(Left->Degree > Right->Degree){
		//left is larger
		Diff->Degree = Left->Degree;
		realloc(Diff->Coeff, Diff->Degree * sizeof(int64_t);
		if (Diff->Coeff == null){
			return false;
		}
		
		for (int i = 0; i < Right->Degree; i++){
			Diff->Coeff[i] = Left->Coeff[i] - Right->Coeff[i];
		}
		
	}
	else if(Left->Degree < Right->Degree){
		//right is larger
		Diff->Degree = Right->Degree;
		realloc(Diff->Coeff, Diff->Degree * sizeof(int64_t);
		if (Diff->Coeff == null){
			return false;
		}
		for (int i = 0; i < Left->Degree; i++){
			Diff->Coeff[i] = Right->Coeff[i] - Left->Coeff[i];
		}	
	}
	else{
		//degrees are the same
		Diff->Degree = Right->Degree;
		realloc(Diff->Coeff, Diff->Degree * sizeof(int64_t);
		if (Diff->Coeff == null){
			return false;
		}
		//TODO a little weird, need a better check to see if degree should be different
		for (int i = 0; i < Left->Degree; i++){
			int sub = Right->Coeff[i] - Left->Coeff[i];
			if (sub == 0 && i = 0){
				Diff->Degree -= 1;
			}
			else if (sub == 0 && Diff->Coeff[i - 1] == 0){
				Diff->Degree -= 1;
			}
		}
		
	}
	return true;
}


bool    Polynomial_Differentiate(Polynomial* const Target, const Polynomial* const Source){
	//update degree
	if (Source->Degree != 0){
		Target->Degree = Source->Degree - 1;
	}
	else{
		Target->Degree = 0;
	}
	
	realloc(Target->Coeff, Target->Degree * sizeof(int64_t);
	if (Target->Coeff == null){
		return false;
	}
	//update coeff
	for (int i = 0; i < Source->Degree; i++){
		//multiple all coeff by their positions in the array
		Source->Coeff[i] = Source->Coeff[i] * i;
		//shift all into target down one power
		if (i != 0){
			Target->Coeff[i - 1] = Source->Coeff[i];
		}
	}
}

//not so sure what he means
bool    Polynomial_Zero(Polynomial* const P){
	P.Degree = 0;
	realloc(P->Coeff, sizeof(int64_t);
}


