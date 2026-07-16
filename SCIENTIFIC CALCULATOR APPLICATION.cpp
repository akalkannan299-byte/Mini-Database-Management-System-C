#include<iostream>
#include<cmath>
# define PI 3.14
using namespace std;
int a[5][5],b[5][5],c[5][5];
main()
{
	void basic();
	void scientific();
	void trignometric();
	void matrix();
	void complex();
	int ch=1;
	cout<<"\n------------------------SCIENTIFIC CALCULATOR OPERATIONS----------------------------------"<<endl;
	while(ch)
	{
		int choice;
		cout<<"-----OPERATING MODES-----\n1.BASIC\n2.SCIENTIFIC\n3.TRIGNOMETRIC\n4.MATRIX\n5.COMPLEX"<<endl;
		cout<<"ENTER YOUR MODE: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:basic();break;
			case 2:scientific();break;
			case 3:trignometric();break;
			case 4:matrix();break;
			case 5:complex();break;
            default: cout<<"INVALID CHOICE"<<endl;
		}
		cout<<"DO YOU WANT TO CONTINUE WITH NEXT MODE"<<endl;
		cin>>ch;
	}
}

void basic() 
{
	int ch=1;
	while(ch)
	{
	char exp[10];
    int result = 0;
    int num = 0;
    int lastTerm = 0;
    char op = '+';
    
    cout<<"ENTER THE EXPRESSION TO BE EVALUATED (with operators +,-,*,/) : ";
    cin>>exp;

    for (int i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            num = num * 10 + (exp[i] - '0');
        }

        if ((!isdigit(exp[i]) && exp[i] != ' ') || exp[i + 1] == '\0') {

            if (op == '+') {
                result += lastTerm;
                lastTerm = num;
            }
            else if (op == '-') {
                result += lastTerm;
                lastTerm = -num;
            }
            else if (op == '*') {
                lastTerm = lastTerm * num;
            }
            else if (op == '/') {
                lastTerm = lastTerm / num;
            }

            op = exp[i];
            num = 0;
        }
    }

    result += lastTerm;
    cout<<"RESULT IS "<<result;
    
    cout<<"\nDO YOU WANT TO CONTINUE EVALUATING EXPRESSION: ";
    cin>>ch;
	}
}


long long factorial(int n)
{
    if(n < 0) 
		return -1;
    long long fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
	return fact;
}

long long nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long nPr(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

void scientific() 
{
        int choice,ch=1;
        double x, y;
        int n, r;
	while(ch)
	{
        cout << "\n------------- SCIENTIFIC OPERATIONS --------------\n";
        cout << "1. log(x)\n";
        cout << "2. log10(x)\n";
        cout << "3. sqrt(x)\n";
        cout << "4. power(x, y)\n";
        cout << "5. exp(x)\n";
        cout << "6. factorial(n)\n";
        cout << "7. absolute |x|\n";
        cout << "8. floor(x)\n";
        cout << "9. ceil(x)\n";
        cout << "10. round(x)\n";
        cout << "11. modulus (x % y)\n";
        cout << "12. nCr\n";
        cout << "13. nPr\n";

        cout << "ENTER CHOICE: ";
        cin >> choice;

        switch(choice) {
            case 1:
            	cout<<"ENTER A NUMBER FOR WHICH NATURAL LOG IS TO FOUND: ";
                cin >> x;
                if(x > 0) 
					cout << "RESULT = " << log(x);
                else 
					cout << "Invalid input!";
                break;

            case 2:
            	cout<<"ENTER A NUMBER FOR WHICH LOG IS TO FOUND:";
                cin >> x;
                if(x > 0)
					cout << "RESULT = " << log10(x);
                else 
					cout << "INVALID INPUT";
                break;

            case 3:
            	cout<<"ENTER A NUMBER FOR WHICH SQUARE ROOT IS TO FOUND: ";
                cin >> x;
                if(x >= 0) 
					cout << "RESULT = " << sqrt(x);
                else 
					cout << "INVALID INPUT";
                break;

            case 4:
            	cout<<"ENTER BASE AND EXPONENT: ";
                cin >> x >> y;
                cout << "RESULT = " << pow(x, y);
                break;

            case 5:
            	cout<<"ENTER A NUMBER ON THE EXPONENT: ";
                cin >> x;
                cout << "RESULT = " << exp(x);
                break;

            case 6:
            	cout<<"ENTER A NUMBER FOR WHICH FACTORIAL IS TO FOUND: ";
                cin >> n;
                if(n >= 0)
                    cout << "RESULT = " << factorial(n);
                else
                    cout << "Invalid input!";
                break;

            case 7:
                cin >> x;
                cout << "Result = " << fabs(x);
                break;

            case 8:
                cin >> x;
                cout << "Result = " << floor(x);
                break;

            case 9:
                cin >> x;
                cout << "Result = " << ceil(x);
                break;

            case 10:
                cin >> x;
                cout << "Result = " << round(x);
                break;

            case 11:
                int a, b;
                cin >> a >> b;
                if(b != 0)
                    cout << "Result = " << a % b;
                else
                    cout << "Division by zero!";
                break;

            case 12:
                cin >> n >> r;
                if(n >= r)
                    cout << "Result = " << nCr(n, r);
                else
                    cout << "Invalid input!";
                break;

            case 13:
                cin >> n >> r;
                if(n >= r)
                    cout << "Result = " << nPr(n, r);
                else
                    cout << "Invalid input!";
                break;

        }

        cout <<"\nDO YOU WANT TO CONTINUE SCIENTIFIC OPERATIONS : ";
        cin>>ch;
    }
}

void trignometric(){
		float degree , radius;
		int n,ch=1;
    	    
   	while(ch)
	{
		cout << " ENTER DEGREE :";
    	cin >> degree;
	    radius = degree*PI/180;
		cout <<  "--------TRIGNOMETRIC OPERATIONS --------" << endl;
      	cout << "\n  1.SIN\n  2.COS\n  3.TAN\n  4.SEC\n  5.COSECANT\n  6.COTANGENT\n ";
      	cout<<" ENTER YOUR CHOICE :";
    	cin >> n;
    	
	  switch(n)
	    {
    	case 1:
		    if(fabs(sin(radius))<0.0001){
	          cout<< "SIN VALUE IS 0"<<endl;
    	    }
	 	    else{
		      cout << endl << " SIN VALUE : "<< sin(radius) <<endl;
	        }
	    	break;
	    case 2:	
	        if(fabs(cos(radius))<0.0001){
	       	   cout<<"COS VALUE IS 0"<<endl;
		    }
		    else{
		   	   cout<<" COS VALUE :"<<cos(radius)<<endl;
		    }
 		    break;
	    case 3:
	        if(fabs(cos(radius))<0.0001){
			    cout<<" TANGENT VALUE IS INFINITE"<<endl;
		     }
		    else{
	           cout << " TANGENT VALUE : "<< tan(radius) <<endl;
		 	 }
			 break;
    	case 4:
		     if(fabs(cos(radius))<0.0001){
			    cout << " SECANT VALUE IS INFINITE" << endl;
	    	 }
		     else{
			    cout<< " SECANT VALUE : "<< 1/(cos(radius)) <<endl;
	    	 }
		     break;
        case 5:
	         if(fabs(sin(radius))<0.001){
	   	        cout<<"COSINE VALUE IS INFINITE"<<endl;
	         }
	         else{
	       	    cout<<"COSINE VALUE :"<<1/sin(radius )<<endl;
	   	     }
	         break;   
        case 6:
	         if(fabs(sin(radius)) < 0.0001){
                cout << " COTANGENT VALUE IS INFINITE" << endl;
             }
             else{
                cout << " COTANGENT VALUE : " << cos(radius)/sin(radius) << endl;
             }
             break;
             
       }
       
       cout <<" DO YOU WANT TO CONTINUE TRIGNOMETRIC OPERATIONS :";
       cin >> ch;
    
   }
} 

void matrix()
{
	int ch,rows,col,mats,cho=1;
	
	void read(int,int);
	void matadd(int a[5][5],int b[5][5] ,int ,int );
	void matsub(int a[5][5],int b[5][5] ,int ,int );
	void matmul(int a[5][5],int b[5][5] ,int ,int );
	void scalmul(int a[5][5],int ,int );
	void mattra(int a[5][5],int ,int );
	void matdet(int a[5][5],int ,int );
	
	cout<<"ENTER NUMBER OF ROWS AND COLUMNS OF THE MATRIX  :  ";
	cin>>rows>>col;
	read(rows,col);
	
	while(cho){
		
	cout<<"--------MATRIX MENU-------\n1. MATRIX ADDITION\n2. MATRIX SUBTRACTION\n3. MATRIX MULTIPLICATION\n4. SCALAR AND MATRIX MULTIPLIACTION\n5. TRANSPOSE OF A MATRIX\n6. DETERMINENT OF A MATRIX\n\n";
	cout<<"ENTER YOUR CHOICE  :  ";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			cho=1;
			while(cho){
			cout<<"\nWHICH TWO MATRIX IS TO BE ADDED(enter without space)  :  ";
			cin>>mats;
			switch(mats)
			{
				case 11:matadd(a,a,rows,col);break;
				case 12:case 21:matadd(a,b,rows,col);break;
				case 13:case 31:matadd(a,c,rows,col);break;
				case 22:matadd(b,b,rows,col);break;
				case 23:case 32:matadd(b,c,rows,col);break;
				case 33:matadd(c,c,rows,col);break;
			}
			cout<<"DO YOU WANT TO CONTINUE ADDING  :  ";
			cin>>cho;
		}
		break;
		case 2:
			cho=1;
			while(cho){
			cout<<"\nWHICH TWO MATRIX IS TO BE SUBTRACTED(enter without space)  :  ";
			cin>>mats;
			switch(mats)
			{
				case 11:matsub(a,a,rows,col);break;
				case 12:matsub(a,b,rows,col);break;
				case 13:matsub(a,c,rows,col);break;
				case 22:matsub(b,b,rows,col);break;
				case 23:matsub(b,c,rows,col);break;
				case 33:matsub(c,c,rows,col);break;
				case 21:matsub(b,a,rows,col);break;
				case 31:matsub(c,a,rows,col);break;
				case 32:matsub(c,b,rows,col);break;
			}
			cout<<"DO YOU WANT TO CONTINUE SUBTRACTING  :  ";
			cin>>cho;
			}
			break;	
					
		case 3:
			cho=1;
			while(cho){
			cout<<"\nWHICH TWO MATRIX IS TO BE MULTIPLIED(enter without space)  :  ";
			cin>>mats;
			switch(mats)
			{
				case 11:matmul(a,a,rows,col);break;
				case 12:matmul(a,b,rows,col);break;
				case 21:matmul(b,a,rows,col);break;
				case 13:matmul(a,c,rows,col);break;
				case 31:matmul(c,a,rows,col);break;
				case 22:matmul(b,b,rows,col);break;
				case 23:matmul(b,c,rows,col);break;
				case 32:matmul(c,a,rows,col);break;
				case 33:matmul(c,c,rows,col);break;
			}
			cout<<"DO YOU WANT TO CONTINUE MULTIPLYING  :  ";
			cin>>cho;
			}
			break;
			
		case 4:
			cho=1;
			while(cho){
			cout<<"\nWHICH MATRIX IS TO BE MULTIPLIED  :  ";
			cin>>mats;
			switch(mats)
			{
				case 1:scalmul(a,rows,col);break;
				case 2:scalmul(b,rows,col);break;
				case 3:scalmul(c,rows,col);break;
			}
			cout<<"DO YOU WANT TO CONTINUE MULTIPLYING  :  ";
			cin>>cho;
			}
			break;

		case 5:
			cho=1;
			while(cho){
			cout<<"\nWHICH MATRIX IS TO BE TRANSPOSED  :  ";
			cin>>mats;
			switch(mats)
			{
				case 1:mattra(a,rows,col);break;
				case 2:mattra(b,rows,col);break;
				case 3:mattra(c,rows,col);break;
			}
			cout<<"DO YOU WANT TO CONTINUE TRANSPOSING  :  ";
			cin>>cho;
			}
			break;
			
		case 6:
			cho=1;
			while(cho){
			cout<<"\nFOR WHICH MATRIX DETERMINENT IS TO BE FOUND  :  ";
			cin>>mats;
			switch(mats)
			{
				case 1:matdet(a,rows,col);break;
				case 2:matdet(b,rows,col);break;
				case 3:matdet(c,rows,col);break;
			}
			cout<<"DO YOU WANT TO CONTINUE FINDING DETERMINENT  :  ";
			cin>>cho;
			}
			break;
	}
	cout<<"\nDO YOU WANT TO CONTINUE MATRIX OPERATION  :  ";
	cin>>cho;}
}
void read(int rows,int col)
{
	
	cout<<"ENTER THREE MATRICES\n\n";
	
	cout<<"FIRST MATRIX"<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]";
			cin>>a[i][j];
		}
	}
	cout<<endl;
	
	cout<<"SECOND MATRIX"<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"b["<<i<<"]["<<j<<"]";
			cin>>b[i][j];
		}
	}
	cout<<endl;
	
	cout<<"THIRD MATRIX"<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<"c["<<i<<"]["<<j<<"]";
			cin>>c[i][j];
		}
	}
	cout<<endl;
}

void matadd(int a[5][5],int b[5][5],int rows,int col)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<col;j++)
		{	cout<<a[i][j]+b[i][j]<<"  ";}
		cout<<"\n";		}
}

void matsub(int a[5][5],int b[5][5],int rows,int col)
{
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++)
		{	cout<<a[i][j]-b[i][j]<<"  ";}
		cout<<"\n";}
}

void matmul(int a[5][5],int b[5][5],int rows,int col)
{
	if(rows!=col)
	{
		cout<<"ONLY SQUARE MATRIX CAN HAVE A MULTIPLIED"<<endl;
	}
	else
	{
	int c[5][5]={0};
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			for(int k=0;k<col;k++)
			{	c[i][j]+=a[i][k]*b[k][j];}
		}
	}
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++)
		{	cout<<c[i][j]<<"  ";}
		cout<<"\n";}
}
}

void scalmul(int a[5][5],int rows,int col)
{
	int s;
	cout<<"ENTER THE SCALAR: ";
	cin>>s;
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++)
		{	cout<<s*a[i][j]<<"  ";}
		cout<<"\n";
	}
}

void mattra(int a[5][5],int rows,int col)
{
	int arr[5][5];
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++)
		{	arr[j][i]=a[i][j];}
		cout<<"\n";
	}
	for(int i=0;i<col;i++){
		for(int j=0;j<rows;j++)
		{	cout<<arr[i][j]<<" ";}
		cout<<"\n";
	}
	
	
}

void matdet(int a[5][5],int r,int c)
{
	if(r==c)
	{
		if(r==2)
			cout<<"DETERMINENT IS"<<a[0][0]*a[1][1] - a[0][1]*a[1][0]<<endl;
		if(r==3)
			cout<<"DETERMINENT IS"<<a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
      - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
      + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0])<<endl;
	}
	else
		cout<<"ONLY SQUARE MATRIX CAN HAVE A DETERMINENT"<<endl;
}

void complex(){
	
	double  r1 , r2 , i1 , i2  , rad , theta ,degree;
	int n , ch=1;
	
    cout << " \n\nENTER FIRST COMPLEX NUMBER : ";
	cin >> r1 >> i1;
	cout << r1 ;
	if(i1 >= 0)
       	cout << "+" << i1 << "i";
    else
       	cout << "-" << -i1 << "i";
	cout<<endl;

	
	
	cout << " \n\nENTER SECOND COMPLEX NUMBER :";
	cin >> r2 >> i2;
	cout <<r2;
	if(i2 >= 0)
       	cout << "+" << i2 << "i";
    else
       	cout << "-" << -i2 << "i";
	cout<<endl;

	
	while(ch)
	{
        cout << " \n------ COMPLEX OPERATIONS-----\n \n ";
	    cout<<"\n  1.ADDITION \n  2.SUBTRACTION\n  3.MULTIPLICATION\n  4.DIVITION\n  5.CONJUCATE\n  6.MODULUS\n  7.ANGLE\n  8.RECTANGULAR TO POLAR CONVERSION\n  9.POWER OF THE COMPLEX NUMBER\n  10.nth ROOT OF THE COMPLEX NUMBER \n ";
	    cin>>n;
	    
		switch(n)
		{
		case 1:
			cout << " COMPLEX NUMBER ADDITION  :" << (r1+r2)  ; 
			if((i1+i2) >= 0)
            	cout << "+" << i1+i2 << "i";
            else
            	cout << "-" << -(i1+i2) << "i";
			cout<<endl;
			break;
			
		case 2:
		    cout << " COMPLEX NUMBER SUBTRACTION :" << (r1-r2) ; 
			if((i1-i2) >= 0)
            	cout << "+" << i1-i2 << "i";
            else
            	cout << "-" << -(i1-i2) << "i";
			cout<<endl;

			break;
			
		case 3:
		    cout << " COMPLEX NUMBER MULTIPLICATION :" << (r1*r2 - i1*i2) ;
			if((r1*i2 + i1*r2) >= 0)
            	cout << "+" << r1*i2 + i1*r2 << "i";
            else
            	cout << "-" << -(r1*i2 + i1*r2) << "i";
			cout<<endl;

		    break;
		    
	    case 4:
		    cout << " COMPLEX NUMBER DIVISION :" << (r1*r2 +i1*i2)/( r2*r2+ i2*i2) ;
			if( ( (i1*r2 -r1*i2)/(r2*r2+ i2*i2) ) >= 0)
            	cout << "+" << (i1*r2 -r1*i2)/(r2*r2+ i2*i2) << "i";
            else
            	cout << "-" << -( (i1*r2 -r1*i2)/(r2*r2+ i2*i2) ) << "i";
			cout<<endl;

		    break;
		    
		case 5:
	        cout << "CONJUGATE FOR C1 : " << r1;
            if(-i1 >= 0)
            	cout << "+" << -i1 << "i";
            else
            	cout << "-" << i1 << "i";

            cout << endl;
            cout << "CONJUGATE FOR C2 : " << r2;

            if(-i2 >= 0)
            	cout << "+" << -i2 << "i";
            else
            	cout << "-" << i2 << "i";
            cout << endl;
	    	break;
	    	
		case 6:
			cout << " MODULUS OF Z1 : "<< sqrt(r1*r1+i1*i1) << endl;	 
			cout << "  MODULUS OF Z2 : "<< sqrt(r2*r2+i2*i2) << endl;	 
			break;
			
	    case 7:
		     cout << " ANGLE : " << atan(i1/r1) << " DEGREE :  " << atan(i1/r1)*180/PI  << endl; 
		     cout << " ANGLE : " << atan(i2/r2) << " DEGREE :  " << atan(i2/r2)*180/PI  << endl;
		    break;
		    
		case 8:
		     rad = sqrt(r1*r1 + i1*i1);
             theta = atan2(i1, r1);
             cout << " POLAR FORM FOR C1 : " << rad << " (cos " << theta*180/PI << " + i sin " << theta*180/PI  << ")" << endl;
             rad = sqrt(r2*r2 + i2*i2);
             theta = atan2(i2, r2);
             cout << " POLAR FORM FOR C2 : " << rad << " (cos " << theta*180/PI << " + i sin " << theta*180/PI  << ")" << endl;
             break;
             
		case 9:
		    double r_pow, angle, p;
            cout << "INPUT POWER: ";
            cin >> p;
            
            rad  = sqrt(r1*r1 + i1*i1);
            theta = atan2(i1, r1);
            r_pow = pow(rad, p);
            angle = p * theta;
            
            cout << "POWER FOR C1: ";
            
            cout << r_pow * cos(angle);
            if (r_pow * sin(angle) >= 0)
            	cout << " + " << r_pow * sin(angle) << "i";
            else
            	cout << " - " << -r_pow * sin(angle) << "i";
            cout << endl;
            
            cout << " INPUT POWER : ";
            cin >> p;
            
            rad = sqrt(r2*r2 + i2*i2);
            theta = atan2(i2, r2);
            r_pow = pow(rad, p);
            angle = p * theta;
            
            cout << " POWER FOR C2: ";
            
            cout << r_pow * cos(angle);
            if (r_pow * sin(angle) >= 0)
            	cout << " + " <<  r_pow * sin(angle) << "i";
            else
            	cout << " - " << -r_pow * sin(angle) << "i";
            cout << endl;
            break;
            
		case 10:
			double real,imag;
			
		    cout << " ENTER ROOT (n): ";
            cin >> n;
            
            rad = sqrt(r1*r1 + i1*i1);
            theta = atan2(i1, r1);
            
            double root_r = pow(rad , 1.0/n);
            cout << "ROOT FOR  C1:" << endl;
            
            for(int k = 0; k < n; k++) 
            	angle = (theta + 2 * M_PI * k) / n;
           
            real = root_r * cos(angle);
            imag = root_r * sin(angle);
            cout << real;
            if(imag >= 0)
            	cout << " + " <<  imag << "i" << endl;
            else
            	cout << " - " << -imag << "i" << endl;
            	
            cout << "ENTER ROOT (n): ";
            cin >> n;
            
            rad = sqrt(r2*r2 + i2*i2);
            theta = atan2(i2, r2);
            root_r = pow(rad, 1.0/n);
            
            cout << "ROOT FOR  C2:" << endl;
            for(int k = 0; k < n; k++) 
            	angle = (theta + 2 * M_PI * k) / n;
            
            real = root_r * cos(angle);
            imag = root_r * sin(angle);
            cout << real;
            
        	if(imag >= 0)
            	cout << " + " <<  imag << "i" << endl;
            else
            	cout << " - " << -imag << "i" << endl;
        	cout << endl;
       }
       cout<<"DO YOU WANT TO CONTINUE COMPLEX OPERATIONS: ";
       cin>>ch;
   }
}

