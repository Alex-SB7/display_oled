# 💡 Voltímetro Digital com RP2040 e I²C

Este repositório contém a implementação de uma prática utilizando o microcontrolador **RP2040 (Raspberry Pi Pico W)** junto à placa **BitDogLab**, com o objetivo de construir um voltímetro digital. A prática envolve leitura de tensão analógica por meio de um joystick e exibição dos valores em tempo real utilizando comunicação I²C com o monitor serial da BitDogLab.

## ⚙️ Descrição do Projeto

- Utiliza o **ADC (Conversor Analógico-Digital)** do RP2040 para captar a tensão analógica do joystick.
- Transforma os valores lidos (0 a 4095) em tensões no intervalo de **0 a 3,3V**.
- Usa o protocolo **I²C** para enviar os valores ao display embutido da BitDogLab.
- O sistema funciona como um voltímetro digital de baixa escala e alta precisão.

## 📦 Componentes Utilizados

- ✅ Microcontrolador RP2040 (Raspberry Pi Pico W)
- ✅ Placa BitDogLab (com display e suporte a I²C)
- ✅ Joystick analógico (entrada de tensão variável)

## 📺 Demonstração

🔗 *Link para o vídeo de funcionamento do projeto:*  
**https://youtu.be/wCP8I3mgz1c**

## 🧠 Conceitos Aplicados

- Conversão Analógico-Digital (ADC)
- Comunicação I²C com dispositivos embarcados
- Leitura e exibição de dados em tempo real
- Processamento de sinais analógicos em sistemas embarcados

## 📄 Licença

Este projeto é livre para fins educacionais.
