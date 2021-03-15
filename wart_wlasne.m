function x= wart_wlasne(A)
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
%w tym miejscu nale?y dostosowa? ilo?? wektorów y w zale?nosci do rozmiaru
%macierzy wejsciowej
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
disp('Macierz a');
disp([y2 y1 y0]);
disp('Macierz b');
disp(y3);
disp('Wektor wspolczynnikow p');
disp(p);
wart_wlasne=roots(p);
x=sort(wart_wlasne);


end