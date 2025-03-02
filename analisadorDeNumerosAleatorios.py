import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Gerando 10.000 números aleatórios normalmente distribuídos
dados = np.random.normal(loc=50, scale=15, size=10000)  # Média=50, Desvio Padrão=15

# Criando um DataFrame para análise
df = pd.DataFrame(dados, columns=['Valores'])

# Estatísticas básicas
print(df.describe())

# Criando um histograma para visualizar a distribuição dos dados
plt.figure(figsize=(10, 5))
plt.hist(df['Valores'], bins=50, color='royalblue', edgecolor='black', alpha=0.7)
plt.title('Distribuição de Dados Gerados Aleatoriamente')
plt.xlabel('Valor')
plt.ylabel('Frequência')
plt.grid(True)
plt.show()
