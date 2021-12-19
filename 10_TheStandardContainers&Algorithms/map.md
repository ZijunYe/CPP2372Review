# map 
- (key:value) 
- key must unique
- value is hidden for user 
- sorted based on the key value 
- associative container 

- map is collection of pairs

## How to initialize the map? 
```
map<KeyType,valueType> name; 
map[keyValue] = value; 

map.insert(pair<keyType,valueType>(key,value)); 
map.insert(make_pair(key,value)); 
map.insert(currIterator,pairValue); 
```

- insert will return as pair key is iterator, and value is boolean 
- if insert successful, then is true, otherwise is false
- pair < keyType,valueType>(key,value) == make_pair(key,value); 


## How to access key value and value? 
iterator->first //get key value 
iterator -> second // get value 

## other method of map: 
```
m.find(keyValue); //return the itertaor position(pointer)
m.erase(iteratorPosition); 
m.count(keyValue); //return 0 or 1, check if the key exist or not 
```

## muti-map 
- can have duplicate key 
