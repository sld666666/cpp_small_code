#ifndef ISINGLETON_H
#define ISINGLETON_H

template <typename T>
class ISingleton 
{
private:
	struct ObjectCreator
	{
		ObjectCreator() 
		{ 
			ISingleton<T>::instance();
		}

		inline void do_nothing() const { }
	};
	static ObjectCreator objCreator_;

protected:
	ISingleton(){};
public:
	static T & instance()
	{
		static T obj;
		objCreator_.do_nothing();
		return obj;
	}
};

template <typename T>  
typename ISingleton<T>::ObjectCreator ISingleton<T>::objCreator_;

#endif // ISINGLETON_H
