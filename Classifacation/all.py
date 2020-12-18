import numpy as np
from sklearn.pipeline import Pipeline
from sklearn.datasets import fetch_20newsgroups
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network.multilayer_perceptron import MLPClassifier
from sklearn.svm import SVC,LinearSVC,LinearSVR
from sklearn.linear_model.stochastic_gradient import SGDClassifier
from sklearn.linear_model.logistic import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.ensemble import AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier
import time

# 选取下面的8类
selected_categories = [
    'comp.graphics',
    'rec.motorcycles',
    'rec.sport.baseball',
    'misc.forsale',
    'sci.electronics',
    'sci.med',
    'talk.politics.guns',
    'talk.religion.misc']

# 加载数据集
newsgroups_train=fetch_20newsgroups(subset='train',
                                    categories=selected_categories,
                                    remove=('headers','footers','quotes'))
newsgroups_test=fetch_20newsgroups(subset='train',
                                    categories=selected_categories,
                                    remove=('headers','footers','quotes'))
# newsgroups_train=fetch_20newsgroups(subset='train')
# newsgroups_test=fetch_20newsgroups(subset='train')

train_texts=newsgroups_train['data']
train_labels=newsgroups_train['target']
test_texts=newsgroups_test['data']
test_labels=newsgroups_test['target']
print(len(train_texts),len(test_texts))

# 贝叶斯
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',MultinomialNB())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("MultinomialNB准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# SGD
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',SGDClassifier())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("SGDClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# LogisticRegression
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',LogisticRegression())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("LogisticRegression准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# SVM
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',SVC())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("SVC准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',LinearSVC())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("LinearSVC准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',LinearSVR())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("LinearSVR准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# MLPClassifier
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',MLPClassifier())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("MLPClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# KNeighborsClassifier
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',KNeighborsClassifier())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("KNeighborsClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# RandomForestClassifier
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',RandomForestClassifier(n_estimators=8))])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("RandomForestClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# GradientBoostingClassifier
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',GradientBoostingClassifier())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("GradientBoostingClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# AdaBoostClassifier
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',AdaBoostClassifier())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("AdaBoostClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)

# DecisionTreeClassifier
text_clf=Pipeline([('tfidf',TfidfVectorizer(max_features=10000)),
                   ('clf',DecisionTreeClassifier())])
time_start=time.time()
text_clf=text_clf.fit(train_texts,train_labels)
predicted=text_clf.predict(test_texts)
time_end=time.time()
print("DecisionTreeClassifier准确率为：",np.mean(predicted==test_labels),' ',time_end-time_start)