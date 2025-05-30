# GS-Edge-Computing-IoT

## Desenvolvedor

Gusthavo Costa de Melo - RM: 561330

## Descrição do Desafio

As inundações urbanas configuram um sério problema em diversas cidades do Brasil, sobretudo em áreas mais afastadas dos centros. A falta de sistemas de aviso antecipado prejudica a segurança das pessoas, resultando em prejuízos financeiros, interrupções no trânsito e, infelizmente, em mortes. Face a esta situação, é essencial criar soluções tecnológicas acessíveis e eficientes que permitam o acompanhamento em tempo real das condições do ambiente e a emissão de avisos preventivos.

## Objetivo

Criar um sistema físico que possa emitir alertas utilizando sensores para mitigar danos.

## Abordagem da Solução

Este código implementa um sistema de monitoramento de enchentes utilizando um sensor ultrassônico, três LEDs de indicação, um buzzer (alarme sonoro) e um display LCD I2C para exibir informações ao usuário. O projeto foi desenvolvido para detectar o nível da água em um ambiente, podendo ser usado em locais vulneráveis a alagamentos, como porões, ruas ou margens de rios.

## Elementos Utilizados

**Sensor Ultrassônico (HC-SR04)** - Mede a distância entre o sensor e o nível da água.

**LEDs (Verde, Amarelo e Vermelho)** - Indicam visualmente a situação do nível da água.

**Buzzer** - Emite um alarme sonoro quando o risco de enchente é crítico.

**Display LCD I2C (20x4)** - Mostra a distância medida em centímetros e o status do sistema.

**Arduino Uno (ou compatível)** - Controlador principal do sistema.

## Visualização

<img src="https://1drv.ms/i/c/9e5ead4592d45130/ERFa6-O-UadLhk7VRO3F5EMBXcbF7QzLbDczF6gcLWy22A?e=bxhkpD">

## Operação do Sistema

Leitura da Distância:
O Arduino envia um pulso pelo pino TRIG do sensor ultrassônico.
O sensor retorna um sinal para o pino ECHO, medindo o tempo de resposta.
A distância até o nível da água é calculada com base no tempo do eco.
Análise da Distância e Classificação do Risco:
Se a distância for maior que 90 cm, o nível da água está baixo (sem risco).

✅ LED verde acende
🔇 Buzzer desligado
🟢 LCD exibe: "Status: Normal"

Se a distância estiver entre 50 cm e 90 cm, a água está subindo (atenção).

🟡 LED amarelo acende
🔇 Buzzer desligado
🟡 LCD exibe: "Status: ALERTA"

Se a distância for menor ou igual a 50 cm, a água está muito próxima (risco de enchente).

🔴 LED vermelho acende
🔊 Buzzer é ativado
🚨 LCD exibe: "!!! ENCHENTE !!!"

Exibição no Display LCD:

Mostra a distância atual e o status do sistema em tempo real.

## Aplicações Possíveis

Sistemas domésticos de alerta de enchentes.

Monitoramento de reservatórios, valas ou bueiros.

Uso em cidades inteligentes (smart cities) para monitoramento preventivo.

## Apresentação em Vídeo

[Vídeo do Projeto](LINK_YOUTUBE)

## Simulação Online

(https://wokwi.com/projects/432298715155035137)

## Organização do Código

O código-fonte está disponível na pasta `src/` com comentários explicativos para ajudar no entendimento: