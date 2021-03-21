N=4145; % size of the Monte Carlo simulation with alpha = 0.01 and error = 0.02
TottalWeight=zeros(N,1); % a vector that keeps the total weight of vehicles that pass over 
% the bridge in a day
k=1;

% F_m,F_a,F_t are poissan variables of motorcyles,automobiles and trucks respectively
% i_m,i_a,i_t are number of  motorcyles,automobiles and trucks passes over 
%bridge in a one day respectively
%G_m,G_a,G_t are gamma variables  of motorcyles,automobiles and trucks respectively 


while(k!=N);
	U=rand; % generating uniform variable 
	F_m = exp(-40);  %
	F_a = exp(-30); 
	F_t = exp(-20); %
	i_m=0; i_a=0; i_t=0; %initial values 
	while(U>=F_m);  %for every k, find the number of motors passes over bridge in a day with lambda =40
		i_m=i_m+1;
		F_m=F_m+exp(-40) * (40^i_m) / gamma(i_m+1);
		
	end;
	
	while(U>=F_a); %for every k, find the number of automobiles passes over bridge in a day with lambda =30
		i_a=i_a+1;
		F_a=F_a+exp(-30) * (30^i_a) /gamma(i_a+1);
		
	end;
	
	while(U>=F_t); %for every k, find the number of trucks passes over bridge in a day with lambda =20
		i_t=i_t+1;
		F_t=F_t+exp(-20) * (20^i_t)/gamma(i_t+1);
		
	end;
	
	%Find gamma variables 
	G_m=sum((-1/(0.15)) * log(rand(16,1))); 
	G_a=sum(((-1)/(0.05)) * log(rand(60,1)));
	G_t=sum(((-1)/(0.01))* log(rand(84,1)));
	TottalWeight(k)=(G_m*i_m)+(G_a*i_a)+(G_t*i_t);
	k=k+1;
end;

P_estimation=mean(TottalWeight>220000);
expectedWeight= mean(TottalWeight);
stdWeight= std(TottalWeight);
fprintf('Estimated probability = %f\n',P_estimation);
fprintf('Expected weight = %f\n',expectedWeight);
fprintf('Standard deviation = %f\n',stdWeight);


