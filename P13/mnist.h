#ifndef MNIST_H_INCLUDED
#define MNIST_H_INCLUDED

#include <MNIST/mnist_reader.h>
#include <cstdint>
#include <vector>

class Mnist
{
public:
    Mnist()
    {
        dataset=mnist::read_dataset<std::vector,std::vector,uint8_t,uint8_t>();
    }
    std::vector<std::vector<uint8_t>>& get_imagenes_test()
    {
        return dataset.test_images;
    }
    std::vector<uint8_t>& get_etiquetas_test()
    {
        return dataset.test_labels;
    }
    std::vector<std::vector<uint8_t>>& get_imagenes_entrenamiento()
    {
        return dataset.training_images;
    }
    std::vector<uint8_t> get_imagen_test(unsigned indice)
    {
        return dataset.test_images[indice];
    }
    std::vector<uint8_t>& get_etiquetas_entrenamiento()
    {
        return dataset.training_labels;
    }
	unsigned get_num_etiquetas()
	{
		return num_etiquetas;
	}
private:
    struct mnist::MNIST_dataset<std::vector,std::vector<uint8_t>,uint8_t> dataset;
	const unsigned num_etiquetas = 10;
};

#endif // MNIST_H_INCLUDED
