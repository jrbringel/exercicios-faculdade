# Análise de Dados com Pandas: Estatísticas detalhadas sobre Vendas
import pandas as pd
import matplotlib.pyplot as plt

dados = {
    "Produto": ["A", "B", "C", "D", "E"],
    "Quantidade": [10, 15, 7, 20, 12],
    "Preco_Unitario": [5.0, 7.5, 3.0, 12.0, 8.5]
}
df = pd.DataFrame(dados)
df["Total_Venda"] = df["Quantidade"] * df["Preco_Unitario"]
print("Resumo das Vendas:")
print(df)
print("Faturamento total:", df["Total_Venda"].sum())

plt.bar(df["Produto"], df["Total_Venda"], color='blue')
plt.xlabel("Produtos")
plt.ylabel("Total de Vendas")
plt.title("Vendas por Produto")
plt.show()