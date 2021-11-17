const add = (a, b, callback) => {
    console.log('I am here');
    const re = a + b;
    setTimeout(() => {
        console.log('He');
        callback (re); 
    }, 2000);
    console.log('Add\n');
}

const exe = () => {
    console.log('Started');
    add(3, 5, (data) => {
        console.log('exe\n');
        console.log('Result: ', data);
    });
    console.log('Finished\n');
}

exe();