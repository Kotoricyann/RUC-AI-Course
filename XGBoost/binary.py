import numpy as np
import matplotlib.pyplot as plt
import xgboost as xgb
from sklearn import metrics


trainfile = np.loadtxt('./dataset/train.csv', skiprows=1 , delimiter=',' )
testfile = np.loadtxt('./dataset/test.csv', skiprows=1 , delimiter=',' )
validationfile = np.loadtxt('./dataset/validation.csv', skiprows=1 , delimiter=',' )

traindata = trainfile[:,0:-1]
trainlabel = trainfile[:,-1]

testdata = testfile[:,0:-1]
testlabel = testfile[:,-1]

validdata = validationfile[:,0:-1]
validlabel = validationfile[:,-1]

dtrain=xgb.DMatrix(traindata,label=trainlabel)
dtest=xgb.DMatrix(testdata)
dvalid=xgb.DMatrix(validdata,label=validlabel)

params={'booster':'gbtree',
    'objective': 'binary:logistic',
    'eval_metric': 'auc',
    'gamma':0.1,
    'max_depth':10,
    'lambda':10,
    'subsample':0.8,
    'colsample_bytree':0.75,
    'min_child_weight':2,
    'eta': 0.025,
    'seed':0,
    'nthread':8,
}
eval_set = [(dtrain,'train'), (dvalid,'valid')]
#print(eval_set)

bst = xgb.train(params, dtrain,num_boost_round=10,evals=eval_set )

ypred=bst.predict(dtest)
# 设置阈值, 输出一些评价指标，选择概率大于0.5的为1，其他为0类
y_pred = (ypred >= 0.5)*1

print ('AUC: %.4f' % metrics.roc_auc_score(testlabel,ypred))
print ('ACC: %.4f' % metrics.accuracy_score(testlabel,y_pred))
print ('Recall: %.4f' % metrics.recall_score(testlabel,y_pred))
print ('F1-score: %.4f' %metrics.f1_score(testlabel,y_pred))
print ('Precesion: %.4f' %metrics.precision_score(testlabel,y_pred))
print(metrics.confusion_matrix(testlabel,y_pred))