import jieba
from wordcloud import WordCloud
import matplotlib.pyplot as plt
from imageio.v2 import imread
import os


# path = "testwordcloud/"
#
# with open(os.path.join(path, '2020_report.txt'), 'r', encoding='utf-8') as f:
#     data = f.read()
# sentences = data.split('#')
#
# with open(os.path.join(path, 'stopword.txt'), 'r', encoding='utf-8') as f:
#     stopwords = f.readlines()
# stopwords = [word.strip() for word in stopwords]
# stopwords.append('\n')
#
# mask = imread(os.path.join(path, 'chinamap.png'))
#
# for i, sentence in enumerate(sentences):
#     words = list(jieba.cut(sentence))
#     words_dict = {}
#
#     for word in words:
#         if word in stopwords:
#             words.remove(word)
#         else:
#             words_dict[word] = words_dict.get(word, 0) + 1
#
#     wc = WordCloud(font_path=os.path.join(path, 'simhei.ttf'), background_color='white', mask=mask)
#     wc.generate_from_frequencies(words_dict)
#
#     plt.subplot(2, 4, i + 1)
#     plt.axis('off')
#     plt.imshow(wc)
#
# plt.show()

path = "testwordcloud/"

plt.rcParams["font.sans-serif"] = [u"SimHei"]
plt.rcParams["axes.unicode_minus"] = False

with open(os.path.join(path, '2023hc.txt'), 'r', encoding='utf-8') as f:
    data = f.read()

with open(os.path.join(path, 'stopword.txt'), 'r', encoding='utf-8') as f:
    stopwords = f.readlines()
stopwords = [word.strip() for word in stopwords]
stopwords.append('\n')

mask = imread(os.path.join(path, 'chinamap.png'))

words = list(jieba.cut(data))
words_dict = {}

for word in words:
    if word not in stopwords:
        words_dict[word] = words_dict.get(word, 0) + 1

wc = WordCloud(font_path=os.path.join(path, 'simhei.ttf'), background_color='white', mask=mask)
wc.generate_from_frequencies(words_dict)

plt.axis('off')
plt.title('国家主席习近平二〇二三年新年贺词 词云')
plt.imshow(wc)

plt.show()
