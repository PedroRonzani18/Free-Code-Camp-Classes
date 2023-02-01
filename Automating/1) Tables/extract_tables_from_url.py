import pandas as pd

pd.options.display.max_columns = None
pd.options.display.width = None

simpsons = pd.read_html("https://en.wikipedia.org/wiki/List_of_The_Simpsons_episodes_(season_21%E2%80%93present)")

print(simpsons[1])

