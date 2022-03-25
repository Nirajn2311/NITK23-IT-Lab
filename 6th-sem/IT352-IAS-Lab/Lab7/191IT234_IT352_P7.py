import os

from cryptography.hazmat.primitives import hashes, hmac


def a(secret, hash_algo, n, seed):
    if n == 0:
        return seed
    else:
        h = hmac.HMAC(secret, hash_algo)
        h.update(a(secret, hash_algo, n - 1, seed))
        return h.finalize()


LABEL = "Master secret"
CR = str(int.from_bytes(os.urandom(32), "big"))
SR = str(int.from_bytes(os.urandom(32), "big"))
SEED = (LABEL + CR + SR).encode()
OUTPUT_LENGTH = 20

output_file = open("191IT234_IT352_P7_Output_TC6.txt", "w")

pm_secret = input("Enter pre-master secret: ").encode()
left_pm = pm_secret[0 : len(pm_secret) // 2]
right_pm = pm_secret[len(pm_secret) // 2 :]

md5_half = bytearray()
sha1_half = bytearray()

i = 1
while len(md5_half) < OUTPUT_LENGTH:
    h = hmac.HMAC(left_pm, hashes.MD5())
    h.update(a(left_pm, hashes.MD5(), i, SEED))
    h.update(SEED)
    md5_half.extend(h.finalize())
    i += 1

i = 1
while len(sha1_half) < OUTPUT_LENGTH:
    h = hmac.HMAC(right_pm, hashes.SHA1())
    h.update(a(right_pm, hashes.SHA1(), i, SEED))
    h.update(SEED)
    sha1_half.extend(h.finalize())
    i += 1

result = bytes([_a ^ _b for _a, _b in zip(md5_half, sha1_half)])
m_secret = bytes(result[:OUTPUT_LENGTH])

print("Client Random Number:", CR)
print("Server Random Number:", SR)
print("Master Secret:", m_secret)
output_file.write("Client Random Number: " + CR + "\n")
output_file.write("Server Random Number: " + SR + "\n")
output_file.write("Master Secret: " + str(m_secret) + "\n")

output_file.close()
