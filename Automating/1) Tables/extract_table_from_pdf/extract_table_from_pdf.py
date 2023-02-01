import camelot

"""
pre requisites:
    pip install tk
    pip install ghostscript
    pip install camelot-py
    pip install 'PyPDF2<3.0'
    pip install opencv-python
"""

df = camelot.read_pdf('extract_table_from_pdf/a.pdf', pages='1')
df.export('foo.csv', f='csv', compress=True)
df[0].to_csv('foo.csv')