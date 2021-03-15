function x= wektory_wlasne(A)
% Sprawdzenie czy macierz A jest kwadratowa
[a,aa] = size(A);
 if(a~=aa)
     error("Macierz A nie jest kwadratowa!");
 end
y0=[1;0;0];
 [k,~] = size(y0);
if (k~=a)
    error("Macierz y0 nie jest wektorem nx1")
end
y1=A*y0;
y2=A*y1;
y3=A*y2;
%disp(y3);
%rozwiazanie metoda eliminacji Gaussa
P=[y2 y1 y0 -y3]; %macierz rozszerzona
for i=1:a
    P(i,:)=P(i,:)./P(i,i); %jedynka na miejscach diagonalnych
    for j=1:a
        if i ~= j  
            P(j,:)=P(j,:)-P(i,:) * P(j,i); %zerowanie trójkatne
        end
    end
end
p1=P(:,a+1); %wyznaczenie macierzy niewiadomych 
p=[1;p1];
%disp('Wektor wspolczynnikow p');
%disp(p);
wart_wlasne=roots(p);
lamb=sort(wart_wlasne);

%tutaj nalezy dostosowac ilosc g do rozmiaru macierzy A
for i=1:a
g3=1;
g2=lamb(i,1)+p(2,1);
g1=lamb(i,1)*g2+p(3,1);
MWW(:,i)= g1*y0+g2*y1+g3*y2;
end
disp('Macierz WW nieznormalizowana');
disp(MWW);

x=sort(wart_wlasne);
end