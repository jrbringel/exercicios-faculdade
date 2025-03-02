import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Gerando dados de vendas para 365 dias
np.random.seed(42)  # Garantir reprodutibilidade
dias = pd.date_range(start="2024-01-01", periods=365, freq='D')  # Criando datas do ano todo
vendas = np.random.randint(100, 1000, size=365)  # Valores de vendas diárias entre 100 e 1000

# Criando um DataFrame
df_vendas = pd.DataFrame({'Data': dias, 'Vendas': vendas})

# Exibir estatísticas
print(df_vendas.describe())

# Criando um gráfico de linha para visualizar as vendas ao longo do tempo
plt.figure(figsize=(12, 5))
sns.lineplot(x=df_vendas['Data'], y=df_vendas['Vendas'], color='blue', linewidth=2)

# Configurações do gráfico
plt.title("Vendas Diárias ao Longo do Ano", fontsize=14)
plt.xlabel("Data")
plt.ylabel("Quantidade de Vendas")
plt.xticks(rotation=45)
plt.grid(True)
plt.show()
