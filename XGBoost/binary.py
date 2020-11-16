import numpy as np
import matplotlib.pyplot as plt
#import XGBoost as xgb


trainfile = np.loadtxt('./dataset/train.csv', skiprows=1 , delimiter=',' )
testfile = np.loadtxt('./dataset/test.csv', skiprows=1 , delimiter=',' )
validationfile = np.loadtxt('./dataset/validation.csv', skiprows=1 , delimiter=',' )

data = trainfile[:,0:-1]
label = trainfile[:,-1]

params={'booster':'gbtree',
    'objective': 'binary:logistic',
    'eval_metric': 'auc',
    'max_depth':4,
    'lambda':10,
    'subsample':0.75,
    'colsample_bytree':0.75,
    'min_child_weight':2,
    'eta': 0.025,
    'seed':0,
    'nthread':8,
    'silent':1,
    'nthread': 4}

eval_set = [(data,label)]
print(eval_set)

#xgboost.train(params,data,num_boost_round=10,evals=eval_set )




