import pandas as pd

pd.options.display.max_columns = None
pd.options.display.width = None

df = pd.read_csv("https://football-data.co.uk/mmz4281/2223/E0.csv")

df.rename(columns={'FTHG': 'home_goals', 'FTAG': 'away_goals'}, inplace=True)

print(df)
