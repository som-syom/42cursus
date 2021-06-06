#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

pthread_mutex_t mutex;
void	msleep(int ms)
{
	struct timeval tv1;
	struct timeval tv2;

	gettimeofday(&tv1, NULL);
	long val1 = tv1.tv_sec * 1000 + tv1.tv_usec/1000;
	// printf("%ld %ld\n", tv1.tv_sec, tv1.tv_usec/1000);
	while (1)
	{
		gettimeofday(&tv2, NULL);
		long val2 = tv2.tv_sec * 1000 + tv2.tv_usec/1000;
		if (val2 - val1 >= ms)
			return;
	}
}

void	*test(void *str)
{
	int ret = 111;
	printf("%s", str);
	return ((void *)ret);
}

void	*test1(void *num)
{
	pthread_mutex_lock(&mutex);
	printf("im %d\n", num);
	usleep(300000);
	pthread_mutex_unlock(&mutex);
	return ((void *)num);
}

int main(void)
{
	pthread_t thread;
	int th_ret = 0;
	char str[] = "Hello world\n";
	int ret = pthread_create(&thread, 0, test, str);
	printf("========= pthread test ==============\n");
	printf("ret = %d\n", ret);
	pthread_join(thread, (void *)&th_ret);
	printf("th_ret = %d\n", th_ret);

	printf("========== gettimeofday ============\n");
	struct timeval tp;
	gettimeofday(&tp, 0);
	printf("time : %ld\n", tp.tv_sec);
	usleep(3000000); // 10만당 1초 정도임(부정확함)
	struct timeval tp2;
	gettimeofday(&tp2, 0);
	printf("time : %ld\n", tp2.tv_sec);

	printf("=========== mutex =================\n");
	pthread_t th1;
	pthread_t th2;
	int num = 0;

	pthread_mutex_init(&mutex, 0);
	pthread_create(&th1, 0, test1, (void *)num);
	num++;
	pthread_create(&th2, 0, test1, (void *)num);

	pthread_join(th1, 0);
	pthread_join(th2, 0);

	msleep(5000);
}