# linux-ipc-wrappers

## Examples:
1. [Named Pipes](https://github.com/abbasraza/linux-ipc-wrappers/tree/main/NamedPipes)

```shell
cd NamedPipes
make
./sender
./receiver
```

1. [Posix Message Queue](https://github.com/abbasraza/linux-ipc-wrappers/tree/main/PosixMsgQueue)

```shell
cd PosixMsgQueue
make
./Sender
```
sender sent a message which will stay in the msg queue until receiver removes it

```shell
./Receiver
```

Check if queue exists:
```shell
ls /dev/mqueue/posix_mq

``` 
