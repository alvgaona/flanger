%% Simulación del Flanger

clc 
clear all
close all

% El filtro a implementar será de la forma:
% Representado en ecuaciones en diferencias
% y[n] = x[n] + ax[n-b]

% Donde b es una función del tiempo. En este caso se tomará una sinusoidal
% de frecuencia angular omega_b = 2pi*F_b rad/s

% Para empezar se tomará el solo de una guitarra en un .wav

%[x,Fs] = wavread('single-coil_pickup');
%[x,Fs] = wavread('bass_pickup');
% [x,Fs] = wavread('hard-electric_guitar2');
[x,Fs] = wavread('hard-electric_guitar');
x = x(1:end,1);
L_x = length(x);

% x es la señal de la guitarra muestreada a una frecuencia de sample Fs
% b varía entre 1 us y 1000 us. Por un tema de implementación se muestreará
% el b para obtener b_n a Fs.
b_nmax = round(1E-03*Fs);
b_nmin = round(1E-06*Fs);

n = (1:L_x);
A = 1;

% b(t) = 1000us*sin(2pi*50*t). Esta señal en teoria debería estar
% muestreada también por temas de implementación a Fs.
% Por lo que habría que convertir la señal con OMEGA*Ts = omega_b

F_b = 0.6; % Frecuencia continua. Auditivamente con F_b = 10 es lo máximo que puede variar b a mi criterio.
omega_b = b_nmax*pi*F_b/Fs; % Esto es cuan rápido varía b_n

%% Distintas formas de varir b_n
%b_n = b_nmax*(abs(cos(omega_b*n)+abs(sin(omega_b*n))));
b_n = 3*(abs(cos(omega_b*n)));
%b_n = b_nmax*(abs(sin(omega_b*n)));
%b_n = b_nmax;

b_n = b_n.';
b_n = round(b_n);
a_n = 1;

%% Se aplica el efecto de distorsión
for i=1:L_x
%     if (i-b_n(i)<=0)
%         y(i) = x(i);
%     else
       y(i) = x(i)+a_n*x((1 + mod(i-b_n(i), L_x)));
%     end
end
%wavwrite(y,44100,'single-coil_pickup-fl');
%wavwrite(y,44100,'bass_pickup-fl');
% wavwrite(y,44100,'hard-electric_guitar2-fl');
wavwrite(y,44100,32,'hard-electric_guitar-fl');
%% Gráficos de la señal de entrada, salida y el filtro

nfft = 1024;
omegan = 0:2/nfft:2*(nfft-1)/nfft;
omegan = omegan(1:nfft/2+1);

figure('name','Espectrograma de la señal de entrada')
spectrogram(x,1024,0,nfft);
title('Espectrograma de la entrada ventaneado con Hamming')

figure('name','Espectrograma de la señal de salida')
spectrogram(y,1024,0,nfft);
title('Espectrograma de la salida ventaneado con Hamming')

