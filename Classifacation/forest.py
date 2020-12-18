from sklearn.datasets import fetch_20newsgroups
from pprint import pprint
from sklearn.feature_extraction.text import TfidfVectorizer
import matplotlib.pyplot as plt

# 加载数据集
newsgroups_train = fetch_20newsgroups(subset='train')
# 加载测试集
newsgroups_test=fetch_20newsgroups(subset='test')

# newsgroups_train = fetch_20newsgroups(subset='train',categories=categories)
# newsgroups_test=fetch_20newsgroups(subset='test',categories=categories)


# 提取tfidf特征
vectorizer = TfidfVectorizer()
vectors = vectorizer.fit_transform(newsgroups_train.data)

# MultinomialNB实现文本分类
from sklearn.ensemble import RandomForestClassifier 
from sklearn.metrics import accuracy_score,f1_score

a_list=[]
pre_list=[]

# print("begin")
# for i in range(1,11):
#     a = 2**i
#     a_list.append(a)
#     clf=RandomForestClassifier(n_estimators=a)
#     clf.fit(vectors,newsgroups_train.target)
#     vectors_test=vectorizer.transform(newsgroups_test.data)
#     pred=clf.predict(vectors_test)
#     print(accuracy_score(newsgroups_test.target,pred))
#     pre_list.append(accuracy_score(newsgroups_test.target,pred))
# print("over")

# plt.plot(a_list,pre_list,marker='o')
# plt.ylim(0,1)
# plt.show()

# 训练
clf=RandomForestClassifier(n_estimators=200, min_samples_leaf=3) 
clf.fit(vectors,newsgroups_train.target)

# 提取测试集tfidf特征
vectors_test=vectorizer.transform(newsgroups_test.data)
# 预测
pred=clf.predict(vectors_test)
print("F1 Score:",f1_score(newsgroups_test.target,pred,average='macro'))
print("Accuracy:",accuracy_score(newsgroups_test.target,pred))