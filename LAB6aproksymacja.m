function d= LAB6aproksymacja(x,yreal)
pomoc=0; %zmienna pomocnicza do zmiany wielkości macierzy
m=7; %stopień wielomianu aproksymującego
%x=[1 2 4 7]; %wartości rzędnych (przykładowe)
%yreal=[1.6 2 2.5 3.5]; %wartości odciętych (przykładowe)
pkt=size(x, 2);
s=imresize(pomoc, [1 2*m+1]); %zmiana wielkosci macierzy przechowywujacej zminimalizowane miary odleglosci (S_k)
T=imresize(pomoc, [1 m+1]);
for j=1:2*m+1
for i=1:pkt
	s(j)=s(j)+x(i)^(j-1);   %liczenie kolejnych miar odleglosci
end
end
 
for j=1:m+1
for i=1:pkt
	T(j) = T(j)+ yreal(i)*x(i)^(j-1); %liczenie kolejnych T_k
end
end
 
%wypelnienie macierzy uzywanych w metodzie Gaussa (b-wyrazy wolne, A-wspolczynniki)
b=imresize(pomoc, [m+1 1]);
for i=1:m+1
    	b(i, 1)=T(i);
end
 
A=imresize(pomoc, [m+1 m+1]);
for i=1:m+1
	k=i;
	for j=1:m+1
    	if j==1
    	else
        	k=k+1;
    	end
    	A(i, j)=s(k);
	end
end
 
%Eliminacja Gaussa
[a,aa]  = size(A);
 if(a~=aa)	
error("Macierz  A nie jest  kwadratowa!");
end
 [k,l]  = size(b);
if(k~=a || l~=1)	
error("Macierz b  nie  jest  wektorem nx1!")
end
n=size(b,1);
 X=zeros(n,1);
P=[A b]; 
 for  i=1:n  
P(i,:)=P(i,:)./P(i,i); 
for  j=1:n
if  i ~= j
	P(j,:)=P(j,:)-P(i,:)*P(j,i);
end
end
end
X=P(:,n+1);
 
y=imresize(pomoc, [1 pkt]);
%policzenie wartosci otrzymanego zaaproksymowanego wielomianu dla podanych punktow
for i=1:pkt
	for j=1:m+1
    	y(i)=y(i)+ x(i)^(j-1) * X(j);
	end
end
%liczenie sumy kwadratów błędów aproksymacji
S=0;
for i=1:pkt
    S=S+(y(i)-yreal(i))^2;
end
d=flip(X);
disp ('wektor współczynników wielomianu aproksymującego:');
disp (d);
disp (['Suma kwadratów błędów aproksymacji dla wielomianu aproksymującego stopnia ',num2str(m),' wynosi: ',num2str(S),'']);
