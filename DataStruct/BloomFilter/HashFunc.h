/**************************************
*文件说明:5种字符串哈希算法声明及实现
*作者:高小调
*创建时间:2017年04月28日 星期五 14时08分25秒
*开发环境:Kali Linux/g++ v6.3.0
*来源:http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
****************************************/
#ifndef __HASHFUNC_H__
#define __HASHFUNC_H__
size_t BKDRHash(const char *str){
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++){
		hash = hash * 131 + ch;               
	}
	return hash;
}

size_t SDBMHash(const char *str){
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++){
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;
}

size_t RSHash(const char *str){
	register size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++){
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}

size_t APHash(const char *str){
	register size_t hash = 0;
	size_t ch;
	for (long i = 0; ch = (size_t)*str++; i++){
		if ((i & 1) == 0){
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}else{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}

size_t JSHash(const char *str){
	if (!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
		return 0;
	register size_t hash = 1315423911;
	while (size_t ch = (size_t)*str++){
		hash ^= ((hash << 5) + ch + (hash >> 2));
	}
	return hash;
}
#endif
