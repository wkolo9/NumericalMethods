function x = eliminacjagaussa(A, b)

% Sprawdzenie czy macierz A jest kwadratowa
[a,aa] = size(A);
 if(a~=aa)
     error("Macierz A nie jest kwadratowa!");
 end

 % Sprawdzenie czy macierz b jest wymiarow nx1
 [k,l] = size(b);
 if(k~=a || l~=1)
     error("Macierz b nie jest wektorem nx1!")
 end
 
n=size(b,1);
x=zeros(n,1);
P=[A b]; %macierz rozszerzona
for i=1:n %eliminacja gaussa obliczajaca wartosci p 
    P(i,:)=P(i,:)./P(i,i); %jedynka na miejscach diagonalnych
    for j=1:n
        if i ~= j  
            P(j,:)=P(j,:)-P(i,:) * P(j,i); %zerowanie trójk?tne
        end
    end
end
x=P(:,n+1); %wyznaczenie macierzy niewiadomych x
end   


